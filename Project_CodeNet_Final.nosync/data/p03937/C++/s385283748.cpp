#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

template<class T> inline bool in_range(T y, T x, T H, T W) { return 0<=y&&y<H&&0<=x&&x<W; }

int main() {

  int H, W; cin >> H >> W;
  int sum = 0;
  rep(i, H) {
    string A; cin >> A;
    sum += count(A.begin(), A.end(), '#');
  }

  cout << (sum == H + W - 1 ? "P":"Imp") << "ossible\n";
  
  return 0;
}