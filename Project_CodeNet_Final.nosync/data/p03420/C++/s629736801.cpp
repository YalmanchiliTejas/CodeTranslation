#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define IN(v) cin>>v
#define OUT(v) cout<<v<<endl


int main() {
  int N, K;
  cin >> N >> K;

  LL sum = 0;
  FOR(k, K, N)
    sum += N-k;

  FOR(t, K+1, N+1) {
    FOR(s, t+1, N+1) {
      if (s % t >= K) {
        int x = min(t - (s % t), (N - s + 1));
        sum += x;
        s += x - 1;
      } else
        s += K - (s % t) - 1;
    }
  }
  OUT(sum);

  return 0;
}
