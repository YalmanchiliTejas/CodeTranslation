#include <stdio.h>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;

long long int count_patty(int N, long long int X, long long int *total_num, long long int *patty_num);

int main(){
  
  /* read input */
  int N;
  long long int X;
  scanf("%d", &N);
  scanf("%lld", &X);
  
  /*make table of reference*/
  long long int total_num[51];
  long long int patty_num[51];
  total_num[0] = 1;
  patty_num[0] = 1;
  for(int i = 1; i <= 50; i++){
    total_num[i] = 2*total_num[i-1]+3;
    patty_num[i] = 2*patty_num[i-1]+1;
  }
  
  printf("%lld", count_patty(N, X, total_num, patty_num));
  
  return 0;
}

long long int count_patty(int N, long long int X, long long int *total_num, long long int *patty_num){

  long long int tot_num = total_num[N];
  // X == tot_num
  if(X == tot_num){
    return patty_num[N];
  }
  // X == 0
  else if(X == 0){
    return 0;
  }
  // (tot_num+1)/2 < X < tot_num
  else if((tot_num+1)/2 < X && X < tot_num){
    return patty_num[N-1] + 1 + count_patty(N-1, X-(tot_num+1)/2, total_num, patty_num);
  }
  // X == (tot_num+1)/2
  else if(X == (tot_num+1)/2){
    return patty_num[N-1]+1;
  }
  // 1 < X == (tot_num+1)/2
  else if(X > 1 && X < (tot_num+1)/2){
    return count_patty(N-1, X-1, total_num, patty_num);
  }
  else if(X == 1){
    return 0;
  }
  return 0;
}
