#ifndef __POSIX_SHMEM_H__
#define __POSIX_SHMEM_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define SHM_NAME_MAX_LEN 256
#define MAP_FAILED ((void *) -1)

struct shm_name {
    char *name;
    int name_len;
    int fd;
};

struct shm_size {
    int shm_fd;
    size_t size;
    int ret;
};

struct shm_mmap {
    void *addr;
    size_t length;
    int prot;
    int flags;
    int fd;
    off_t offset;
    void *ret;
};

struct shm_unmap {
    void *addr;
    size_t length;
    int ret;
};

struct shm_unlink {
    char *name;
    int name_len;
    int ret;
};

int shyper_shm_open(const char *name, int oflag, mode_t mode);

int shyper_ftruncate(int fd, off_t length);

void *shyper_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

int shyper_munmap(void *addr, size_t length);

int shm_unlink(const char *name);

#endif