#include <bits/stdc++.h>
using namespace std;

typedef int_fast32_t int32;
typedef int_fast64_t int64;

const int32 inf = 1e9+7;
const int32 MOD = 1000000007;
const int64 llinf = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define all(obj) (obj).begin(),(obj).end()
#define rall(obj) (obj).rbegin(),(obj).rend()
#define fi first
#define se second
#define pb(a) push_back(a)
typedef pair<int32,int32> pii;
typedef pair<int64,int64> pll;

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return true; } return false;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; } return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int64 n,x,m;
  cin >> n >> x >> m;
  vector<int32> visited(m,-1);
  int64 ans = x;
  int64 pre = x;
  visited[x] = 1;
  int64 lpf = -1;
  REP(i,n-1){
    int64 nxt = pre * pre % m;
    if(visited[nxt] != -1){
      lpf = nxt;
      n -= visited[pre];
      break;
    }
    ans += nxt;
    visited[nxt] = visited[pre] + 1;
    pre = nxt;
  }
  // ANS(lpf);
  if(lpf == -1){
    ANS(ans);
    return 0;
  }

  // REP(i,m)cout << visited[i] << " ";
  // cout << endl;

  // ANS(n);

  int64 lpsum = lpf;
  int64 lpl = 1;
  int64 cur = lpf * lpf % m;
  while(cur != lpf){
    lpsum += cur;
    cur = cur * cur % m;
    ++lpl;
  }

  // ANS(lpsum);
  // ANS(lpl);
  
  ans += lpsum * (n / lpl);
  n %= lpl;
  REP(i,n){
    ans += lpf;
    lpf = lpf * lpf % m;
  }
  ANS(ans);
  return 0;
}