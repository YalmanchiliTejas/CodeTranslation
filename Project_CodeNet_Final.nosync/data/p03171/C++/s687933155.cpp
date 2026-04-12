#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
/* テンプレートここまで */
const int MOD = 1e9 + 7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MAX = 3003;
ll dp[MAX][MAX];
ll a[MAX];
bool visited[MAX][MAX];

ll rec(int l, int r){
  if(visited[l][r]) return dp[l][r];
  ll ret;
  if(r == l){
    ret = a[r];
  }else{
    ret = max(a[r] - rec(l,r-1), a[l] - rec(l+1, r));
  }
  visited[l][r] = true;
  return dp[l][r] = ret;
}

int main() {
  int N;  cin >> N;
  REP(i, N) cin >> a[i];

  cout << rec(0, N-1) << endl;
}
