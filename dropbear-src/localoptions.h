/*
 * localoptions.h — Dropbear's official compile-time configuration hook (included by sysoptions.h).
 * NanOS config (not a source patch): public-key auth only. Password/PAM auth need crypt(), which
 * NanOS's libc does not provide; pubkey auth (an authorized_keys entry) is the plan's chosen,
 * cleaner-to-automate model anyway. Keep the feature set lean for a small single-user server.
 */
#ifndef DROPBEAR_LOCALOPTIONS_H
#define DROPBEAR_LOCALOPTIONS_H

#define DROPBEAR_SVR_PASSWORD_AUTH 1   /* password auth: NanOS libc now provides crypt() ($6$) */
#define DROPBEAR_SVR_PAM_AUTH 0
#define DROPBEAR_CLI_PASSWORD_AUTH 1
#define DROPBEAR_SVR_PUBKEY_AUTH 1     /* authorized_keys (still available) */
#define DROPBEAR_CLI_PUBKEY_AUTH 1

#endif /* DROPBEAR_LOCALOPTIONS_H */
