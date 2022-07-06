#!/usr/bin/env bash

CUSTOM_UID=1000

groupadd -f -g $CUSTOM_UID -o test
useradd -N -o -u $CUSTOM_UID test

exec /docker-setuid $CUSTOM_UID /sbin/nginx -g 'daemon off;'
