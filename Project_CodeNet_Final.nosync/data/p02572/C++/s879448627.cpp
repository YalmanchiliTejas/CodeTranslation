#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long ssum[200200];
long long x[200200];
int main()
{
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>x[i];
  for(int i=N-1;i>=0;i--)
    ssum[i]=(ssum[i+1]+x[i])%MOD;
  long long ans=0;
  for(int i=0;i<N;i++)
  {
    long long tmp=x[i]*ssum[i+1]%MOD;
    ans=(ans+tmp)%MOD;
  }
  cout<<ans<<endl;
  return 0;
}