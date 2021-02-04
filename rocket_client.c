 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <pthread.h>

#include <time.h>


int generate_random(int j, int n, int iteration) {
    int i;
    time_t t;
    /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print random numbers from j to n */
   for( int i = j ; i < n ; i++ ) {
      printf("%d\n", rand()%iteration);
   }
   
   return(0);
}
  
pthread_mutex_t data_mutex; 
int counter; 
  
void *tmp_controlSystem()
{ 
    pthread_mutex_lock(&data_mutex);
    generate_random(30, 300, 270);


    pthread_mutex_unlock(&data_mutex);
} 
  
void *tmp_thrusters(void* arg)
{ 
    pthread_mutex_lock(&data_mutex);
    generate_random(-100, +100, 99);

    pthread_mutex_unlock(&data_mutex);
} 

void *acceleration_rocket(void* arg)
{ 
    pthread_mutex_lock(&data_mutex);
     generate_random(2, 20, 18);

    pthread_mutex_unlock(&data_mutex);
} 
void *gyro_rocket(void* arg)
{ 
    pthread_mutex_lock(&data_mutex);
    generate_random(0, 360, 359);

    pthread_mutex_unlock(&data_mutex);
} 

int main(void) 
{ 
   pthread_t tid_uid,tid_pn;
  pthread_create(&tid_uid,NULL,tmp_controlSystem,NULL);
  int pthread_create(&tid_uid,NULL,tmp_thrusters,NULL);
  int pthread_create(&tid_uid,NULL,acceleration_rocket,NULL);
  int pthread_create(&tid_uid,NULL,gyro_rocket,NULL);


    pthread_join(tid_uid, NULL); 
    pthread_join(tid_pn, NULL); 
    pthread_mutex_destroy(&data_mutex);  
    return 0; 
} 
