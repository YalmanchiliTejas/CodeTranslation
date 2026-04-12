#include<bits/stdc++.h>
#include <string> 

using namespace std;
const int mod = 1e9 + 7;
const long long INF = 1e18;
#define PI 3.141592653589793
#define REP(i, n) for(long long i = 0;i < n;i++)
int main()
{
  long long N;
  int A[300000];
  long long  sum=0;
  long long  ans=0;
  cin>>N;
  REP(i,N){
    cin>>A[i];
    sum+=A[i];
  }
  //cout<<ans<<endl;
  for(int i = 0;i < N;i++){
    sum-=A[i];
    ans=(A[i]*(sum%mod)+ans)%mod;
  //cout<<ans<<endl;
  }
  cout<<ans;
  return 0;
}


