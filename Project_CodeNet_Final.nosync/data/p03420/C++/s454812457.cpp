#include <stdio.h>

int main(void){

  long b,c,N,K;

  scanf("%ld", &N);
  scanf("%ld", &K);
  c = 0;
  for(b=K+1; b <= N; b++){
    long a_num = 0;
    a_num += (b-K)*(N/b);
    if( N%b - K +1 > 0){
      a_num += N%b - K+1;		/* 残余 */
    }

    if( K == 0){
      a_num -= 1;		/* 最初a=0は対象外なので */
    }
    c += a_num;


  }

  printf("%ld", c);

}
