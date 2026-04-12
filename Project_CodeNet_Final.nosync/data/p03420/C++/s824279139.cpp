#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define INF 1LL << 62
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i, m) for (int i = 0; i < m; i++)
#define FOR(i, n, m) for (int i = n; i < m; i++)
#define ALL(v) v.begin(),v.end() 
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main(){
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  FOR(i, k+1, n+1){
    if(n%i < k) ans += (i-k)*(n/i);
    else ans += (i-k)*(n/i)+(n%i+1-k);
  }
  if(k == 0) cout << n*n << endl;
  else cout << ans << endl;
  return 0;
}
