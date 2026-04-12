#include <iostream>
#include <algorithm>
using namespace std;

const int DPSIZE = 100005;
const int MAXN = 11;
const int INF = 1<<28;
int N, M;
int V[MAXN];
int dp[DPSIZE];

int main() {
  while(cin >> N >> M && (N|M)) {
    for(int i = 0; i < N; ++i) {
      cin >> V[i];
    }

    int l, r;
    l = 0;
    r = 100001;
    while(r-l) {
      int m = (l+r)/2;
      fill(dp, dp+DPSIZE, INF);
      dp[0] = 0;
      for(int j = 0; j < N; ++j) {
        for(int i = V[j]; i <= M; ++i) {
          dp[i] = min(dp[i], dp[i-V[j]]+1);
        }
        for(int i = 0; i <= M; ++i) {
          dp[i] = dp[i] <= m ? 0 : INF;
        }
      }
      if(dp[M] == 0) {
        r = m;
      } else {
        l = m+1;
      }
    }
    cout << r << endl;
  }
  return 0;
}