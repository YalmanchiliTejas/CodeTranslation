#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, j, n) for (int i = j; i < (int)(n); i++)
#define brep(i, n) for (int i = n; i > 0; i--)
#define BREP(i, j, n) for(int i = n; i > j; i--)
#define TEST cout << "PASS" << endl
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 1e6 + 1e3 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  ll n;
  cin >> n;
  ll a[200000];
  ll s = 0;
  rep(i, n){
    cin >> a[i];
    s += a[i];
    s = s % MOD;
  }
  ll ans = 0;
  rep(i, n){
    s = (s - a[i] + MOD)%MOD;
    ans = (ans + (s* a[i] % MOD))%MOD;
  }
  cout << ans << endl;
}