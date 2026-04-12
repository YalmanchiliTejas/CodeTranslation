#include <iostream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 1<<15;
const ll MOD = 1e9+7;
const double EPS = 1e-9;


int main(int argc, const char * argv[]) {
  int N; cin >> N;
  vector<int> H(N);
  for (int i=0; i<N; i++){
    cin >> H[i];
  }
  
  vector<int> high(N);
  high[0] = H[0];
  for (int i=1; i<N; i++) {
    high[i] = max(high[i-1], H[i]);
  }
  
  int ans = 0;
  for (int i=0; i<N; i++) {
    if (H[i] == high[i]) ans ++;
  }
  cout << ans << endl;
  return 0;
}