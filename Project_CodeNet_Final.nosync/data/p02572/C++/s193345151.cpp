#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  long long A[N],asum[N];fill(asum,asum+N,0);
  for(int i=0;i<N;i++){scanf("%lld",&A[i]);asum[i]=A[i];}
  for(int i=1;i<N;i++)asum[i]=(asum[i]+asum[i-1])%mod;
  long long ans=0;
  for(int i=N-1;i>0;i--)ans=ans+asum[i-1]*A[i]%mod;
  printf("%lld",ans%mod);
}