#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
const double PI = acos(-1);
const double EPS = 1e-10;
const ll MOD = 1000000007;
vl a1(5);
vl sousuu,pat;
void cioacc(){//accelerate cin/cout
  cin.tie(0);
  ios::sync_with_stdio(false);
}
ll solve(ll a,ll x) {
  if(x==0) return 0;
  if(a < 2) return a1[x];
  if(x <= sousuu[a-2]) return solve(a-1,x-1);
  else if(x == sousuu[a-2]+1) return pat[a-2] + 1;
  else if(x >= sousuu[a-1]-1) return pat[a-1];
  else return solve(a-1,x-sousuu[a-2]-2) + pat[a-2] + 1;
}
int main(){
  ll n,x;
  cin >> n >> x;
  sousuu.assign(n,0),pat.assign(n,0);
  sousuu[0] = 5;
  pat[0] = 3;
  a1[0] = 0;
  a1[1] = 1;
  a1[2] = 2;
  a1[3] = 3;
  a1[4] = 3;
  REP(i,n-1) {
    sousuu[i+1] = 2 * sousuu[i] + 3;
    pat[i+1] = 2 * pat[i] + 1;
  }
  cout << solve(n,x-1) << endl;
  
}
 