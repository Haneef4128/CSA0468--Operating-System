#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 0;
pthread_mutex_t lock;

void *increment(void *arg) {
    int x;
    pthread_mutex_lock(&lock);
    x = shared;
    x++;
    sleep(1);
    shared = x;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *decrement(void *arg) {
    int y;
    pthread_mutex_lock(&lock);
    y = shared;
    y--;
    sleep(1);
    shared = y;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&tid1, NULL, increment, NULL);
    pthread_create(&tid2, NULL, decrement, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("Final value of shared is %d\n", shared);
    pthread_mutex_destroy(&lock);
    return 0;
}
