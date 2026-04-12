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
  Task : S - Digit Sum
*/
 
int main(){
  cin.tie(0), cin.sync_with_stdio(0), cout.tie(0), cout.sync_with_stdio(0);

  string s; cin >> s;
  int d; cin >> d;
  const int n = s.size();

  const int MOD = 1e9 + 7;
  vector<vvi> memo(n, vvi(2, vi(d, -1)));

  function<int(int, bool, short)> dp = [&](int i, bool less, short sum) {
    // base case
    if(i == n) return (int)(sum == 0);
    int &ans = memo[i][less][sum];
    if(ans != -1) return ans;
    ans = 0;
    const short lim = (less ? 9 : (s[i] - '0'));
    // cout << "dp " << i << " " << less << " " << sum << ", lim: " << lim << '\n';
    for(short digit = 0; digit <= lim; digit++){
      ans = (ans + dp(i + 1, less | (digit < lim), (sum + digit) % d)) % MOD;
    }
    return ans;
  };

  cout << (dp(0, 0, 0) - 1 + MOD) % MOD;

  return cout << endl, 0;
}