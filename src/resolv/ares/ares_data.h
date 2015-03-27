/* $Id: ares_data.h,v 1.2 2009-11-23 12:03:33 yangtse Exp $ */

/* Copyright (C) 2009 by Daniel Stenberg
 *
 * Permission to use, copy, modify, and distribute this
 * software and its documentation for any purpose and without
 * fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting
 * documentation, and that the name of M.I.T. not be used in
 * advertising or publicity pertaining to distribution of the
 * software without specific, written prior permission.
 * M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 */

#ifndef HAVE_ARES_DATA
#include "resolv/ares/ares_parse_txt_reply.h"
#include "resolv/ares/ares_parse_srv_reply.h"
#endif /* HAVE_ARES_DATA */

typedef enum {
  ARES_DATATYPE_UNKNOWN = 1,  /* unknown data type     - introduced in 1.7.0 */
  ARES_DATATYPE_SRV_REPLY,    /* struct ares_srv_reply - introduced in 1.7.0 */
  ARES_DATATYPE_TXT_REPLY,    /* struct ares_txt_reply - introduced in 1.7.0 */
#if 0
  ARES_DATATYPE_ADDR6TTL,     /* struct ares_addrttl   */
  ARES_DATATYPE_ADDRTTL,      /* struct ares_addr6ttl  */
  ARES_DATATYPE_HOSTENT,      /* struct hostent        */
  ARES_DATATYPE_OPTIONS,      /* struct ares_options   */
#endif
  ARES_DATATYPE_LAST          /* not used              - introduced in 1.7.0 */
} ares_datatype;

#define ARES_DATATYPE_MARK 0xbead

/*
 * ares_data struct definition is internal to c-ares and shall not
 * be exposed by the public API in order to allow future changes
 * and extensions to it without breaking ABI.  This will be used
 * internally by c-ares as the container of multiple types of data
 * dynamically allocated for which a reference will be returned
 * to the calling application.
 *
 * c-ares API functions returning a pointer to c-ares internally
 * allocated data will actually be returning an interior pointer
 * into this ares_data struct.
 *
 * All this is 'invisible' to the calling application, the only
 * requirement is that this kind of data must be free'ed by the
 * calling application using ares_free_data() with the pointer
 * it has received from a previous c-ares function call.
 */

struct ares_data {
  ares_datatype type;  /* Actual data type identifier. */
  unsigned int  mark;  /* Private ares_data signature. */
  union {
    struct ares_txt_reply txt_reply;
    struct ares_srv_reply srv_reply;
  } data;
};

void *_ares_malloc_data(ares_datatype type);
void _ares_free_data(void *dataptr);

ares_datatype ares_get_datatype(void * dataptr);