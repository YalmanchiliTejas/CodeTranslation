#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool fill(int n, string &s, vector<int> &v, int a, int b) {
  v[0] = a;
  v[1] = b;
  for (int i = 1; i <= n; i++) {
      if ((v[i] == 1 and s[i] == 'o') || (v[i] == 0 and s[i] == 'x')) {
      v[i + 1] = !v[i - 1];
    } else {
      v[i + 1] = v[i - 1];
    }
  }
  return v[0] == v[n] and v[1] == v[n+1];
}

void solve(long long N, std::string s) {
  vector<int> v(N+2);
  s.push_back(s[0]);
  auto fin = [&]() {
    string res = "";
    for (int i = 0; i < N; i++) {
      if (v[i]) {
        res.push_back('W');
      } else {
        res.push_back('S');
      }
    }
    cout << res << endl;
  };

  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
	if (fill(N, s, v, i, j)) {
        fin();
        return;
      }
    }
  }
  cout << -1 << endl;
}

int main() {

  long long N;
  scanf("%lld", &N);
  std::string s;
  std::cin >> s;
  solve(N, s);
  return 0;
}
