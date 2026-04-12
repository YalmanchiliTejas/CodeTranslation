#include <bits/stdc++.h>
using namespace std;
long long A[1000000],B[1000000];
int main()
{
  long long i,j,n,c=0;
  scanf("%lld",&n);
  for(i=1;i<=n;i++)
  {
    scanf("%lld",&A[i]);
    B[i]=B[i-1]+A[i];

  }
  for(i=1;i<=n;i++)
  {
    c+=(A[i]*((B[n]-B[i])%1000000007));
    c%=1000000007;
  }
printf("%lld\n",c);
}
