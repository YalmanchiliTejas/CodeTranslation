#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int N , a  ;
	scanf("%d", &N);
	if(N<15)
    {
      printf("%d", N*800)  ;
    }
    else if(N>=15)
    {
      a = N*800 - 200*((int)(N/15));
      printf("%d", a)  ;
    }
}
