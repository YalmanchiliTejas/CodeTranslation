#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  while(true)
  {
    ll n; cin>>n;
    if(n==0) {break;}
    ll m,M,sum=0;
    m=10000;
    M=0;
    rep(i,n)
    {
      ll s; cin>>s;
      sum+=s;
      m=min(m,s);
      M=max(M,s);
    }
    cout<<(sum-M-m)/(n-2)<<endl;
  }  
  return 0;
}


