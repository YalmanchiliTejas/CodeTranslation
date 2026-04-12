#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD=1e9+7;
const int INF32=1<<30;
const ll INF64=1LL<<60;

void solve(){
  ll n,x,m; cin >>n >>x >>m;
  set<ll>s; vector<ll>v; bool ok=1; int cnt=0,rec;
  for(int i=0; i<n; i++){
    s.insert(x); cnt++;
    if(s.size()-cnt){rec=x; ok=0; break;}
    v.push_back(x);
    x*=x; x%=m;
  }
  ll ans=0;
  for(auto i:v) ans+=i;
  if(ok){cout <<ans; return;}
  int q=v.size();
  for(int i=0; i<q; i++) if(v[i]==rec){rec=i; break;}
  ll rem=0;
  for(int i=rec; i<q; i++) rem+=v[i];
  n-=q; ans+=n/(q-rec)*rem; n%=(q-rec); rem=0;
  for(int i=0; i<n; i++) rem+=v[i+rec];
  ans+=rem;
  cout <<ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  //int T; cin >>T; while(T--)
  solve();
return 0;}