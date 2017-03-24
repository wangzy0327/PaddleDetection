#ifndef __PADDLE_CAPI_ARGUMENTS_H__
#define __PADDLE_CAPI_ARGUMENTS_H__

#include <stdint.h>
#include "config.h"
#include "error.h"
#include "matrix.h"
#include "vector.h"

/**
 * Arguments functions. Each argument means layer output. Arguments means a
 * array of arguemnt.
 */
typedef void* paddle_arguments;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief paddle_arguments_create_none Create a array of arguments, which size
 * is zero.
 * @return Arguemnts
 */
PD_API paddle_arguments paddle_arguments_create_none();

/**
 * @brief paddle_arguments_destroy Destroy the arguments
 * @param args arguments to destroy
 * @return paddle_error
 */
PD_API paddle_error paddle_arguments_destroy(paddle_arguments args);

/**
 * @brief PDArgsGetSize Get size of arguments array
 * @param [in] args arguments array
 * @param [out] size array size
 * @return paddle_error
 */
PD_API paddle_error paddle_arguments_size(paddle_arguments args,
                                          uint64_t* size);

/**
 * @brief PDArgsResize Resize a arguments array.
 * @param args arguments array.
 * @param size target size of array
 * @return paddle_error
 */
PD_API paddle_error paddle_arguments_resize(paddle_arguments args,
                                            uint64_t size);

/**
 * @brief PDArgsSetValue Set value matrix of one argument in array, which index
 *        is `ID`.
 * @param args arguments array
 * @param ID array index
 * @param mat matrix pointer
 * @return paddle_error
 */
PD_API paddle_error paddle_arguments_set_value(paddle_arguments args,
                                               uint64_t ID,
                                               paddle_matrix mat);

/**
 * @brief PDArgsGetValue Get value matrix of one argument in array, which index
 *        is `ID`.
 * @param [in] args arguments array
 * @param [in] ID array index
 * @param [out] mat matrix pointer
 * @return paddle_error
 */
PD_API paddle_error paddle_arguments_value(paddle_arguments args,
                                           uint64_t ID,
                                           paddle_matrix mat);

/**
 * @brief PDArgsGetIds Get the integer vector of one argument in array, which
 *        index is `ID`.
 * @param args arguments array
 * @param ID array index
 * @param ids integer vector pointer
 * @return paddle_error
 */
PD_API paddle_error paddle_arguments_ids(paddle_arguments args,
                                         uint64_t ID,
                                         paddle_ivector ids);

/**
 * @brief PDArgsSetIds Set the integer vector of one argument in array, which
 *        index is `ID`.
 * @param [in] args arguments array
 * @param [in] ID array index
 * @param [out] ids integer vector pointer
 * @return paddle_error
 */
PD_API paddle_error paddle_arguments_set_ids(paddle_arguments args,
                                             uint64_t ID,
                                             paddle_ivector ids);

/**
 * @brief PDArgsSetSequenceStartPos Set sequence start position vector of one
 *        argument in array, which index is `ID`.
 * @param args arguments array
 * @param ID array index
 * @param seqPos sequence position array.
 * @return paddle_error
 */
PD_API paddle_error
paddle_arguments_set_sequence_start_pos(paddle_arguments args,
                                        uint64_t ID,
                                        uint32_t nestedLevel,
                                        paddle_ivector seqPos);
/**
 * @brief PDArgsGetSequenceStartPos Get sequence start position vector of one
 *        argument in array, which index is `ID`.
 * @param [in] args arguments array
 * @param [in] ID array index
 * @param [out] seqPos sequence position array
 * @return paddle_error
 */
PD_API paddle_error paddle_arguments_sequence_start_pos(paddle_arguments args,
                                                        uint64_t ID,
                                                        uint32_t nestedLevel,
                                                        paddle_ivector seqPos);

#ifdef __cplusplus
}
#endif

#endif
