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

/*!
 * \file polar_chanalloc.h
 * \brief Declaration of the subchannel allocation block.
 * \author Jesus Gomez
 * \date 2020
 *
 * \copyright Software Radio Systems Limited
 *
 *
 */

#ifndef SRSLTE_CHANALLOC_H
#define SRSLTE_CHANALLOC_H

#include "srslte/config.h"
#include "stdint.h"

/*!
 * Allocates message bits (data + CRC) to the encoder input bit vector at the
 * positions specified in \a K_set\\PC_set, computes and allocates the PC bits and
 * zeros to the remaining positions.
 * \param[in] message A pointer to the vector with the message bits (data and CRC).
 * \param[out] input_encoder A pointer to the encoder input bit vector.
 * \param[in] N The codeword length.
 * \param[in] K Number of data + CRC bits.
 * \param[in] nPC Number of parity check (PC) bits.
 * \param[in] K_set Pointer to the indices of the encoder input vector containing.
 * \param[in] PC_set Pointer to the indices of the parity check bits.
 */
void srslte_polar_chanalloc_tx(const uint8_t*  message,
                               uint8_t*        input_encoder,
                               const uint16_t  N,
                               const uint16_t  K,
                               const uint8_t   nPC,
                               const uint16_t* K_set,
                               const uint16_t* PC_set);

/*!
 * Extracts message bits (data + CRC) from the decoder output vector
 * according to the positions specified in \a K_set\\PC_set.
 * \param[in] output_decoder A pointer to the decoder output bit vector.
 * \param[out] message A pointer to the vector with the message bits (data and CRC).
 * \param[in] K Number of data + CRC bits.
 * \param[in] nPC Number of parity check (PC) bits.
 * \param[in] K_set Pointer to the indices of the encoder input vector containing.
 * \param[in] PC_set Pointer to the indices of the parity check bits.
 */
void srslte_polar_chanalloc_rx(const uint8_t*  output_decoder,
                               uint8_t*        message,
                               const uint16_t  K,
                               const uint8_t   nPC,
                               const uint16_t* K_set,
                               const uint16_t* PC_set);

#endif // SRSLTE_CHANALLOC_H
