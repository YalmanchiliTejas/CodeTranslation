#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
const int MOD = (int)1e9 + 7;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  vector<int> H(N);
  int ans = 1;

  REP(i, N) {
    cin >> H[i];

  }
  int highest=H[0];
  FOR(i,1,N){
    if(highest<=H[i]){
      ans++;
    }
    if(highest<H[i]){
      highest=H[i];
    }


  }
  cout << ans << endl;

  return 0;
}
