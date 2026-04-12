#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
using pll = pair<long,long>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back

vll rem(1e5+5,0),vec(1e5+5,0);

int main() {
  ll n,x,m,first=0,period=0;
  cin>>n>>x>>m;
  ll sum=0,ans=0;

  for(ll i=1;i<=m-1;i++) {
    rem[i]=x;
    if(vec[x]!=0) {
      first=vec[x];
      period=i-first;
    }
    vec[x]=i;
    x*=x;
    x%=m;
  }
  if(first!=0) {
    for(ll i=first;i<=first+period-1;i++) sum+=rem[i];
  } else {
    if(m==1) {
      ans=0;
    } else {
      for(ll i=1;i<=m-1;i++) sum+=rem[i];
      ans+=sum*(n/(m-1));
      n%=(m-1);
      for(ll i=1;i<=n;i++) ans+=rem[i];
    }
    cout<<ans<<endl;
    return 0;
  }

  if(n<=first) {
    for(ll i=1;i<=n;i++) ans+=rem[i];
  } else {
    for(ll i=1;i<=first-1;i++) ans+=rem[i];
    n-=first-1;
    ans+=sum*(n/period);
    n%=period;
    for(ll i=first;i<=first+n-1;i++) ans+=rem[i];
  }

  cout<<ans<<endl;
}
