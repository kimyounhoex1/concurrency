typedef struct __lock_t {
    int flag;
} lock_t;


int TestAndSet(int *old_ptr, int new){
    int old = *old_ptr;
    *old_ptr = new;
    return old;
}


void init(lock_t *lock) {
    lock->flag = 0;
}

void lock(lock_t *s) {
    while (TestAndSet(&lock->lock, 1) == 1) {
        // Busy-wait
    }
}

void unlock(lock_t *lock) {
    lock->flag = 0;
}