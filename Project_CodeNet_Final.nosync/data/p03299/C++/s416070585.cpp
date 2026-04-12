#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair

const int MOD = (int)1e9 + 7;

int pow(int x, int k){
  if(k==0) return 1;
  int p = pow(x,k/2);
  p = (p * 1ll * p) % MOD;
  if(k % 2) p = (p * 1ll * x) % MOD;
  return p;
}

pii solve(vector<int> hh){
  int low = (int)1e9;
  for(auto x : hh)
    low = min(low, x);
  vector<int> cur;
  vector<pii> sols;
  int emp = 0;
  for(int i = 0 ; i < hh.size(); i ++ ){
    hh[i] -= low;
    emp += (hh[i] == 0);
    if(hh[i] != 0) cur.push_back(hh[i]);
    if(hh[i] == 0 || i + 1 == hh.size()){
      if(!cur.empty()) sols.push_back(solve(cur));
      cur.clear();
    }
  }
  ll a1 = 1;
  for(auto x : sols)
    a1 = (a1 * 1ll * x.fi) % MOD;
  a1 = (a1 * 1ll * pow(2,low)) % MOD;
  ll a2 = pow(2,emp);
  ll a3 = (pow(2,low) - 2);
  for(auto x : sols){
    a2 = (a2 * 1ll * (x.fi + x.se)) % MOD;
    a3 = (a3 * 1ll * x.fi) % MOD;
  }
  return mp(a1, (a2+a3)%MOD);
}

int main(){
  int n;
  cin >> n;
  vector<int> sol;
  int a;
  for(int i = 1; i <= n; i ++ ){
    cin >> a;
    sol.push_back(a);
  }
  pii res = solve(sol);
  cout << res.se << "\n";
  return 0;
}