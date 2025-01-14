/*
 * Copyright (c) 2011 Mark Heily <mark@heily.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef  _KQUEUE_POSIX_PLATFORM_H
#define  _KQUEUE_POSIX_PLATFORM_H

/* Required by glibc for MAP_ANON */
#define __USE_MISC 1

#include "../../include/sys/event.h"

#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <poll.h>
#include <sys/resource.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>

/*
 * Additional members of 'struct eventfd'
 */
#define EVENTFD_PLATFORM_SPECIFIC \
    int ef_wfd

void    posix_kqueue_free(struct kqueue *);
int     posix_kqueue_init(struct kqueue *);

int     posix_kevent_wait(struct kqueue *, const struct timespec *);
int     posix_kevent_copyout(struct kqueue *, int, struct kevent *, int);

int     posix_eventfd_init(struct eventfd *);
void    posix_eventfd_close(struct eventfd *);
int     posix_eventfd_raise(struct eventfd *);
int     posix_eventfd_lower(struct eventfd *);
int     posix_eventfd_descriptor(struct eventfd *);

#endif  /* ! _KQUEUE_POSIX_PLATFORM_H */
