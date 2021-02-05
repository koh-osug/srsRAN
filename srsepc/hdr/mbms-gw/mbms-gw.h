/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2020 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

/******************************************************************************
 * File:        mbms-gw.h
 * Description: Top-level MBMS-GW class. Creates and links all
 *              interfaces and helpers.
 *****************************************************************************/

#ifndef MBMS_GW_H
#define MBMS_GW_H

#include "srslte/asn1/gtpc.h"
#include "srslte/common/buffer_pool.h"
#include "srslte/common/log_filter.h"
#include "srslte/common/logmap.h"
#include "srslte/common/threads.h"
#include "srslte/srslog/srslog.h"
#include "srslte/srslte.h"
#include <cstddef>

namespace srsepc {

const uint16_t GTPU_RX_PORT = 2152;

typedef struct {
  std::string name;
  std::string sgi_mb_if_name;
  std::string sgi_mb_if_addr;
  std::string sgi_mb_if_mask;
  std::string m1u_multi_addr;
  std::string m1u_multi_if;
  int         m1u_multi_ttl;
} mbms_gw_args_t;

struct pseudo_hdr {
  uint32_t src_addr;
  uint32_t dst_addr;
  uint8_t  placeholder;
  uint8_t  protocol;
  uint16_t udp_len;
};

class mbms_gw : public srslte::thread
{
public:
  static mbms_gw* get_instance(void);
  static void     cleanup(void);
  int             init(mbms_gw_args_t* args, srslte::log_ref mbms_gw_log);
  void            stop();
  void            run_thread();

private:
  /* Methods */
  mbms_gw();
  virtual ~mbms_gw();
  static mbms_gw* m_instance;

  int      init_sgi_mb_if(mbms_gw_args_t* args);
  int      init_m1_u(mbms_gw_args_t* args);
  void     handle_sgi_md_pdu(srslte::byte_buffer_t* msg);
  uint16_t in_cksum(uint16_t* iphdr, int count);

  /* Members */
  bool                  m_running;
  srslte::log_ref       m_mbms_gw_log;
  srslog::basic_logger& m_logger = srslog::fetch_basic_logger("MBMS");

  bool m_sgi_mb_up;
  int  m_sgi_mb_if;

  bool               m_m1u_up;
  int                m_m1u;
  struct sockaddr_in m_m1u_multi_addr;
};

} // namespace srsepc

#endif // SGW_H
