#include<iostream>
#include<time.h>
using namespace std;
#define size 100000
void f1()
{
   timespec start, end;
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
   int static_Array[size];
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
   cout <<"For static declaration in function f1 " <<(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)<<" miliseconds"<<endl;
}
void f2()
{
   timespec start, end;
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
   int* Onstack_Array=new int[size];
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
   cout <<"For declaration on stack in function f2 " <<(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)<<" miliseconds"<<endl;
}
void f3()
{
   timespec start, end;
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
   int *Onheap_Array = (int*)malloc(sizeof(int) * size);
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
   cout <<"For declaration on heap in function f3 " <<(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)<<" miliseconds"<<endl;
}
int main()
{
   f1();
   f2();
   f3();
}