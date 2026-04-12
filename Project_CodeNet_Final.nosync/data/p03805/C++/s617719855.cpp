#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vi a(M), b(M);
  rep(i, M) cin >> a[i] >> b[i];

  vi perm(N);
  int ans = 0;
  rep(i, N) perm[i]=i+1;
  do {
    if (perm[0] != 1) continue;
    bool check = false;
    for (int i =1; i < N; i++) {
      check = false;
      rep(j, M) {
        if ((perm[i-1] == a[j] && perm[i] == b[j]) || (perm[i-1] == b[j] && perm[i] == a[j])) check = true;
      }
      if (!check) break;
    }
    if (check) ans+=1;
  }while(next_permutation(all(perm)));
  cout << ans << endl;
}
