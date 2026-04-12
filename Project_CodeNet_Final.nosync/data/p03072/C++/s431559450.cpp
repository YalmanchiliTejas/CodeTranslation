#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << "DEBUG>" << #x << ":" << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  REP(i, N) {
    cin >> H[i];
  }
  int h = H[0];
  int ans = 0;
  REP(i, N) {
    if(H[i] >= h) {
      ans++;
    }
    h = max(h, H[i]);
  }
  cout << ans << endl;
  return 0;
}
