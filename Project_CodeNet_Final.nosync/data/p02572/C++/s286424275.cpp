#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <numeric>
 
#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define rrep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

 
int main(void){
  
  //vector<vector<char>> maze(h, vector<char>(w));
  //vector<vector<ll>> warp(h, vector<ll>(w, INF));
  
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll res=0;
  ll su = 0;
  
  rep(i,n){
    ll e;
    cin >> e;
    a.at(i) = e;
    su += e;
  }
  
  rep(i,n-1){
    ll k = a.at(i);
    su -= k;
    res += (su%MOD*k%MOD)%MOD;
  }
  
  cout << res%MOD << endl;
}
