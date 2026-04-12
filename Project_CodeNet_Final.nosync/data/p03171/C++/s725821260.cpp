#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int N;
ll a[3100];
ll dp[3100][3100];

ll rec(int i, int j)
{
  if(i>j) return 0;
  if(dp[i][j] > 0) return dp[i][j];
  if(i==j) return a[i];
  
  ll res;
  res = max(a[i] - rec(i+1, j), a[j] - rec(i, j-1));
  return dp[i][j] = res;
}

int main(){
  cin >> N;
  rep(i, N) cin >> a[i];

  cout << rec(0, N-1) << endl;

  return 0;
}
