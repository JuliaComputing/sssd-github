/*
    SSSD

    Authors:
        Fabiano Fidêncio <fidencio@redhat.com>

    Copyright (C) 2017 Red Hat

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef IPA_DESKPROFILE_CONFIG_H_
#define IPA_DESKPROFILE_CONFIG_H_

#include <talloc.h>
#include <tevent.h>

#include "providers/ldap/ldap_common.h"
#include "db/sysdb.h"

/* From ipa_deskprofile_config.c */
struct tevent_req *
ipa_deskprofile_get_config_send(TALLOC_CTX *mem_ctx,
                                struct tevent_context *ev,
                                struct sdap_handle *sh,
                                struct sdap_options *opts,
                                struct dp_option *ipa_opts);

errno_t
ipa_deskprofile_get_config_recv(struct tevent_req *req,
                                TALLOC_CTX *mem_ctx,
                                struct sysdb_attrs **config);

#endif /* IPA_DESKPROFILE_CONFIG_H_ */
