#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

int main() {
  int N; cin >> N;
  ll s[N]; rep(i, N) cin >> s[i];

  ll result = 0;
  for (int i=1; i<N; i++) {
    ll tmp=0, j=1;
    while (i*(j+1)<N-1) {
      if (i*j==(N-1)-i*j || i*j-((N-1)-i*j)==i) break;
      tmp += s[i*j] + s[(N-1)-i*j];
      result = max(result, tmp);
      j++;
    }
  }
  cout << result << endl;
  return 0;
}