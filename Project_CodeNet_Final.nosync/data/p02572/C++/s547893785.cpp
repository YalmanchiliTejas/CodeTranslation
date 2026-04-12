#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main() {
  ll N, S{}, S2{}, A;
  cin >> N;
  while(cin >> A) {
    S = (S + A)%(MOD*2);
    S2 = (S2 + A * A)%(MOD*2);
  }
  ll ans = ((S*S) - S2)%(MOD*2)/2;
  cout << ans << endl;
}
