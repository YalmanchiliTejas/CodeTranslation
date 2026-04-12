#include<stdio.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
const int MOD=1e9+7;
int main(void)
{
  int N,A[200000],cusum=0,total=0;
  if(!scanf("%d",&N))return -1;
  rep(i,N){if(!scanf("%d",&A[i]))return -1;cusum=(1l*cusum+A[i])%MOD;}
  rep(i,N){cusum-=A[i];if(cusum<0){cusum+=MOD;}total=(1l*total+1l*A[i]*cusum%MOD)%MOD;}
  return printf("%d\n",total),0;
}