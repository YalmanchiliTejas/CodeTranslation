#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
  int N;
  cin >> N;
  VI result;
  rep(i, N) {
    int a;

    cin >> a;
    a *= -1;
    int id = 0;
    id = upper_bound(result.begin(), result.end(), a) - result.begin();
    if (id != (int)result.size()) {
      result.at(id) = a;
    } else {
      result.push_back(a);
    }
  }
  cout << result.size() << endl;
  return 0;
}
