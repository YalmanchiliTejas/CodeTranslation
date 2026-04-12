#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  int ans = 1, M = 0;
  cin >> M;
  for (int i = 0; i < N - 1; i++) {
    int tmp;
    cin >> tmp;
    if (tmp >= M) ans++;
    M = max(M, tmp);
  }
  cout << ans << endl;
}