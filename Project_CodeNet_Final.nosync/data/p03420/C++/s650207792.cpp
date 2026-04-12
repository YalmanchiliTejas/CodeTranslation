#include<bits/stdc++.h>
using namespace std;
constexpr int64_t mod=1e9+7;
using ll=long long int;

int main()
{
  ll n,k,cnt=0;
  cin>>n>>k;
  for (int b = 1; b <= n; ++b)
  {
    ll p=n/b,r=n%b;
    cnt+=max(b-k,0LL)*p;
    cnt+=max(r-k+1,0LL);
  }
  if(k==0) cout<<cnt-n;
  else cout<<cnt;
}