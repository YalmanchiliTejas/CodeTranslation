#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

long long size(int n){
  return (long long)pow(2,n+2)-3;
}

long long p(int n){
  return (long long)pow(2,n+1)-1;
}

long long f(int n, long long x){
  //printf("f(%d, %lld) called\n",n,x);
  if (n==0){
    return 1;
  } else if (x==0){
    return 0;
  } else if (x<=size(n-1)){
    return f(n-1, x-1);
  } else if (x==size(n-1)+1){
    return (long long)p(n-1)+1;
  } else if (x<2*size(n-1)+2){
    return p(n-1)+1+f(n-1, x-size(n-1)-2);
  } else if (x==2*size(n-1)+2){
    return p(n);
  } else {
    return -1;
  }
}

int main(){

  int N;
  long long X;
  scanf("%d", &N);
  scanf("%lld", &X);
  long long ans = f(N, X-1);
  printf("%lld\n", ans);
  return 0;
}
