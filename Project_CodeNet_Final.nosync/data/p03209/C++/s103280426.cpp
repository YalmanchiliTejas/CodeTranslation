#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << "DEBUG>" << #x << ":" << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)

vector<long long> bg_len(51);
vector<long long> pt(51);
long long ans(int N, long long X) {
  if(N == 0) return 1;
  if(X == 1) {
    return 0;
  } else if(2 <= X && X <= bg_len[N - 1] + 1) {
    return ans(N - 1, X - 1);
  } else if(X == 1 + bg_len[N - 1] + 1) {
    return pt[N - 1] + 1;
  } else if(bg_len[N - 1] + 3 <= X) {
    return pt[N - 1] + 1 + ans(N - 1, X - bg_len[N - 1] - 2);
  }
}

int main() {
  int N;
  long long X;
  cin >> N >> X;
  bg_len[0] = 1;
  pt[0] = 1;
  REP(i, 50) {
    bg_len[i + 1] = 2 * bg_len[i] + 3;
    pt[i + 1] = 2 * pt[i] + 1;
  }
  long long a = ans(N, X);
  cout << a << endl;
  return 0;
}
