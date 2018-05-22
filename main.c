#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "threadpool.h"

void *run(void *arg)
{
    int i = *(int*)arg;
    free(arg);
    printf("thread %lu working %d\n", pthread_self(), i);
    sleep(1);
}

int main( void )
{
        threadpool_t pool;

        threadpool_init(&pool, 3);
        int i;
        for (i=0; i<10; i++) {
            int *p = (int*)malloc(sizeof(int));
            *p = i;
            threadpool_add(&pool, run, (void*)p);
        }

        threadpool_destroy(&pool);
}

