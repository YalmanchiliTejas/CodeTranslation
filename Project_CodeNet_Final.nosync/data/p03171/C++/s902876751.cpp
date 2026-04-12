#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int N;
ll A[3002], B[3002];
ll DP[3001][3001]; //　Aのindexがどれぐらいすすんだのか、Bのindexがどれぐらいすすんだのか
bool U[3001][3001];
ll dfs_s(int, int);
ll dfs_t(int, int);

ll dfs_s(int a_idx, int b_idx){
  if (U[a_idx][b_idx]) return DP[a_idx][b_idx];
  if ((a_idx+b_idx) == N) return 0;
  ll c_s = dfs_t(a_idx+1, b_idx) + A[a_idx];
  ll c_t = dfs_t(a_idx, b_idx+1) + B[b_idx];
  ll res = max(c_s, c_t);
  DP[a_idx][b_idx] = res;
  U[a_idx][b_idx] = true;
  return res;
}

ll dfs_t(int a_idx, int b_idx){
  if (U[a_idx][b_idx]) return DP[a_idx][b_idx];
  if ((a_idx+b_idx) == N) return 0;
  ll c_s = dfs_s(a_idx+1, b_idx) - A[a_idx];
  ll c_t = dfs_s(a_idx, b_idx+1) - B[b_idx];
  ll res = min(c_s, c_t);
  DP[a_idx][b_idx] = res;
  U[a_idx][b_idx] = true;
  return res;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  ll a = 0;
  rep(i, N){
    cin >> a;
    A[i] = a;
    B[N-1-i] = a;
  }

  ll ans = dfs_s(0, 0);
  cout << ans << endl;
  return 0;
}