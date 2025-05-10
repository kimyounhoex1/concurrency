#include <stdio.h>
#include <pthread.h>

static volatile int counter = 0;

void *mythread(void *arg) {
    for (int i = 0; i < 100000000; i++) {
        counter++;
    }
    printf("%s: done\n", (char *) arg);
    return NULL;
}

void lock(){
    DisableInterruptes();
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, mythread, "Thread 1");
    pthread_create(&t2, NULL, mythread, "Thread 2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", counter);
    return 0;
}