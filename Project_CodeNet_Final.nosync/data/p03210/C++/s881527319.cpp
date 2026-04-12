#include <bits/stdc++.h>
using namespace std; void solve(); int main() {cin.tie(0); ios::sync_with_stdio(false); cout<<fixed<<setprecision(10); solve();}
using ll = int_fast64_t; using ld = long double;
#define SELECTOR(_1, _2, _3, SELECT, ...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__, _rep1, _rep0)(__VA_ARGS__)
#define _rep0(i, n) for (ll i = 0; i < n; ++i)
#define _rep1(i, k, n) for (ll i = k; i < n; ++i)
#define dump(x) cout << #x << " = " << x << "\n";
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template <typename T> void vecout(const T &v) { for(auto it=v.begin();it!=v.end();++it,cout<<(it!=v.end()?" ":"\n")) cout << *it; }

void solve(){
  ll x; cin>>x;
  if(x==7||x==5||x==3) cout<<"YES"<<"\n";
  else cout<<"NO"<<"\n";
}
