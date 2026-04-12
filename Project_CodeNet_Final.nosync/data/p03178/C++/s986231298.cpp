// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

ll dp[10001][101];

int main(int argc, char const* argv[])
{
  string s;
  int d;
  cin >> s >> d;
  int curr = 0;
  rep(i, s.size()){
    int num = int(s[i] - '0');
    rep(j, d){
      rep(k, 10){
        int tmp = (j - k) % d;
        if(tmp < 0)tmp += d;
        dp[i+1][j] = (dp[i+1][j] + dp[i][tmp]) % mod;
      }
    }
    rep(k, num){
      dp[i+1][(curr + k) % d] = (dp[i+1][(curr + k) % d] + 1) % mod;
    }
    curr += num;
  }
  dp[s.size()][curr % d]++;
  ll res = (dp[s.size()][0] - 1) % mod;
  if(res < 0)res += mod;
  cout << res << endl;
	return 0;
}
