#!/bin/sh
# mknx the SSH keygen + client too (nanos-port only mknx's the `binary` = dropbear server).
# Write the .nxe into $PORT (bind-mounted, persists) — the stage cwd is ephemeral.
# Arch-aware: NX_HOST selects the cross triple (x86_64-nanos default; x86_64-nanos for ARCH=x86_64),
# so the right per-arch mknx packs the ELF32/ELF64 binary into a v3/v4 .nxe.
set -e
MKNX="${NX_HOST:-x86_64-nanos}-mknx"
for b in dropbearkey dbclient; do
    [ -f "$b" ] && "$MKNX" "$b" "$PORT/$b.nxe" --need libc.ndl && echo "mknx $b.nxe -> $PORT" || true
done
