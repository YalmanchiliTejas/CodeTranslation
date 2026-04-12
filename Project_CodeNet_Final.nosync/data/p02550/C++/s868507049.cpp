/*
 © 2020-09-19 08:02:22 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
  lli n, x, m; cin >> n >> x >> m;
  vector<lli> v = {x};
  vector<lli> vv;
  set<lli> st = {x};
  lli res = x;
  n--;
  while(n--){
    x = (x * x) % m;
    if(st.count(x)){
      n++;
      bool yes = false;
      fore(i, 0, sz(v)){
        if(v[i] == x) yes = true;
        if(yes) vv.pb(v[i]);
      }
      break;
    }
    st.insert(x);
    v.pb(x);
    res += x;
    if(x == 0){
      cout << res << ENDL;
      return 0;
    }
  }
  if(!vv.empty()){
    fore(i, 1, sz(vv)) vv[i] += vv[i - 1];
    res += vv.back() * (n / sz(vv));
    n -= sz(vv) * (n / sz(vv));
    if(n and n % sz(vv)) res += vv[n % sz(vv) - 1];
  }
  cout << res << ENDL;
  return 0;
}
