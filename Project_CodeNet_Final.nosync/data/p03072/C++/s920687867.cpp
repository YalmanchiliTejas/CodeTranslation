#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long int ll;

using namespace std;

int main() {
  int N, H;
  cin >> N;
  int ans = 0;
  int highest = numeric_limits<int>::min();
  REP(i, N) {
    cin >> H;
    if(H >= highest) {
      highest = H;
      ans++;
    }
  }
  cout << ans << endl;
}