#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  char key = s[k - 1];
  for (int i = 0; i < n; i++) {
    if (s[i] != key) s[i] = '*';
  }
  cout << s << endl;
}