#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,ans=0,a,b,prev;cin>>n>>m;
  vector<lvector> G(n);
  rep(i,m) {
    cin>>a>>b;a--,b--;
    G[a].emplace_back(b),G[b].emplace_back(a);
  }
  lvector v;rep(i,n-1) v.emplace_back(i+1);
  bool isok;
  do {
    isok=true;
    prev=0;
    for(ll i:v) {
      if(find(ALL(G[prev]),i)!=G[prev].end()) prev=i;
      else {isok=false;break;}
    }
    if(isok) ans++;
  } while(next_permutation(ALL(v)));
  print(ans);
  return 0;
}