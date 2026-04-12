#include <bits/stdc++.h>
using namespace std;

using LL = long long;

#define ALL(a) begin((a)), end((a))
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define RFOR(i, a, b) for (int(i) = (a); (i) > (b); (i)--)
#define debug(x) cout << #x << " : " << x << '\n'

const int INF = 1e9;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int ans;
  int N;
  cin >> N;
  vector<LL> a(N);
  FOR(i, 0, N) { cin >> a[i]; }

  vector<LL> b(N);

  int a_index = N - 1;
  int b_index = 0;
  while (a_index >= 0) {
    b[b_index] = a[a_index];
    a_index -= 2;
    b_index++;
  }

  a_index = N % 2;
  while (a_index < N) {
    b[b_index] = a[a_index];
    a_index += 2;
    b_index++;
  }

  FOR(i, 0, N) { cout << b[i] << ' '; }

  cout << '\n';

  return 0;
}