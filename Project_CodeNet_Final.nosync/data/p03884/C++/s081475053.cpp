#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef vector<vl> mt;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<string> vs;
typedef vector<vs> table;
typedef vector<vl> v2;
typedef vector<v2> v3;
typedef vector<v3> v4;


const ll e5 = 1 << 20;
const ll mods[] = {998244353, 1000000007, 1000000009};
const ll bases[] = {997, 1009, 1013};
// const ll mod = mods[0];
const ll e3 = 1 << 13;
const ll INF = 1ll << 50;

ll k;
string festival = "FESTIVAL";
string ans;
const ll base = 256;

void dfs(ll d, ll k){
  if(d == -1) return;
  k--;
  while(k%256 != 0){
    k--;
    ans += festival[d];
  }
  if(k == 0) return;
  dfs(d-1, k/256);
  for(ll i = 0;i < 256;i++){
    ans += festival[d];
  }
}

int main(){
  cin >> k;
  ans = festival;
  dfs(7, k);
  cout << ans << endl;
  vl cnt(128, 0);
  unordered_map<ll,ll> m;
  m[festival[0]] = 0;
  for(ll i = 1;i < festival.size();i++){
    m[festival[i]] = festival[i-1];
  }
  cnt[0] = 1;
  for(ll i = 0;i < ans.size();i++){
    cnt[ans[i]] = cnt[ans[i]] + cnt[m[ans[i]]];
  }
  cerr << cnt['L'] << " " << k << endl;
  assert(cnt['L'] == k);
  assert(ans.size() <= 5000);





}
