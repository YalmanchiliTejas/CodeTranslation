#include <bits/stdc++.h> 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using vb = vector<bool>;
 
const int INF = 2e9+5;
const ll LLINF = (1LL << 60) + 5;
 
/*
  filippos
  Contest : AtCoder DP contest
  Task : L - Deque
*/
 
int main(){
  cin.tie(0), cin.sync_with_stdio(0), cout.tie(0), cout.sync_with_stdio(0);

  int n; cin >> n;
  vi v(n);
  for(int &i : v)
    cin >> i;

  ll tot = accumulate(v.begin(), v.end(), 0LL);

  vvl memo(n, vll(n, -1));
  function<ll(int, int)> dp = [&](int i, int j){
    if(i > j) return 0LL;
    ll &ans = memo[i][j];
    if(ans != -1) return ans;
    return ans = max(
      v[i] + min(dp(i + 2, j), dp(i + 1, j - 1)),
      v[j] + min(dp(i, j - 2), dp(i + 1, j - 1)));
  };

  ll x = dp(0, n-1);
  ll y = tot - x;

  cout << x - y;

  return cout << endl, 0;
}