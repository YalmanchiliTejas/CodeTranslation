
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;


int main() {
  ll n;
  cin>>n;
  vector<ll> a(n);

  rep(i,n)cin>>a[i];
  multiset<ll> st;
  st.insert(INF);
  rep(i,n){
    if (*st.begin()>=a[i]){
      st.insert(a[i]);
    }
    else{
      auto it=st.lower_bound(a[i]);
      it--;
      st.erase(it);
        st.insert(a[i]);
    }
  }
cout<<st.size()-1;
}
