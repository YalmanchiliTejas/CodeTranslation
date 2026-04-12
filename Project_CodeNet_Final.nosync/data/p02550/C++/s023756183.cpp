#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n,x,m;
  cin>>n>>x>>m;
  vector<ll> a={x};
  set<ll> st={x};
  ll tgt;
  while (true) {
    ll b=a.back();
    ll tmp=st.size();
    a.push_back(b*b%m);
    st.insert(b*b%m);
    if (st.size()==tmp) {
      tgt=a.back();
      break;
    }
  }
  ll j=0;
  ll ans=0;
  for (int i = 0; i < a.size(); ++i)
  {
    if (a[i]==tgt) {
      j=i;
      ans+=tgt;
      break;
    }
    ans+=a[i];
  }
  a.erase(a.begin(),a.begin()+j+1);
  ll cycle = a.size();
  ll sum=accumulate(a.begin(), a.end(),0LL);
  n-=j+1;
  ans+=n/cycle*sum;
  for (int i = 0; i < n%cycle; ++i)
  {
    ans+=a[i];
  }
  cout<<ans<<endl;
}