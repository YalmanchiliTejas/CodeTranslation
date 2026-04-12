#include <bits/stdc++.h>

using namespace std;

#define int long long
#define PB push_back
typedef pair<int, int> pii;
static const int INF = 1LL<<61;

pii go[100005];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n, n) {
    fill(go, go + 100005, pii(-1, -1));
    int head = 0, a;
    cin >> a;
    go[0] = pii(a, 1);
    for (int i = 2; i <= n; ++i) {
      cin >> a;

      if (i % 2 == 1 || go[head].first == a) {
	if (go[head].first != a) {
	  head++;
	  go[head] = pii(a, 1);
	  continue;
	}
	go[head].second++;
	continue;
      }

      if (0 < head && go[head - 1].first == a) {
	go[head - 1].second += go[head].second + 1;
	go[head] = pii(-1, -1);
	head--;
      } else {
	go[head] = pii(a, go[head].second + 1);
      }
    }

    int ans = 0;
    for (int i = 0; i <= head; ++i) {
      if (go[i].first == 0) ans += go[i].second;
    }
    
    cout << ans << endl;
  }
  
  return 0;
}