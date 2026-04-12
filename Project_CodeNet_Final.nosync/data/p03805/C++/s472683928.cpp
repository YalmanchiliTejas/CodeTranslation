#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvs = vector<vs>;
using pii = pair<int, int>;
using vpii = vector<pii>;

int main() {
  int N, M, x, y, p, q, tmp = 0;
  cin >> N >> M;
  vi apex(N);
  vpii side(M);
  int ans = 0;
  bool judge = false;
  
  rep(i, N) {
    tmp++;
    apex.at(i) = tmp;
  }
  
  rep(i, M) {
    cin >> x >> y;
    side.at(i) = make_pair(x, y);
  }
  
//  sort(apex.begin(), apex.end());
  do {
    if (apex.at(0) != 1) break;
    rep(j, N-1) {
      judge = false;
      rep(k, M) {
        tie(p, q) = side.at(k);
        if (p == apex.at(j) && q == apex.at(j+1)) {
          judge = true;
          break;
        } else if (p == apex.at(j+1) && q == apex.at(j)) {
          judge = true;
          break;
        }
      }
      if (!judge) break;      
    }
    if (judge) ans++;
  } while (next_permutation(apex.begin(), apex.end()));
  
  cout << ans << endl;
}

