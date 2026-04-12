#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll stages[51];
ll pattys[51];

ll search(ll level, ll X) {
  if (level == 0) {
    return X == 1 ? 1 : 0;
  }

  if (X <= 1 + stages[level - 1]) {
    return search(level - 1, X - 1);
  } else if (1 + stages[level - 1] < X) {
    return pattys[level - 1] + 1 + search(level - 1, X - 2 - stages[level - 1]);
  }
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORR(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)

#define CHMIN(a, b) (a) = min((a), (b))
#define CHMAX(a, b) (a) = max((a), (b))

int main() {
  ll n;
  ll x;
  cin >> n >> x;
  stages[0] = 1;
  pattys[0] = 1;

  FOR(i, 1, n + 1) {
    pattys[i] = pattys[i - 1] * 2 + 1;
    stages[i] = stages[i - 1] * 2 + 3;
  }

  ll ans = 0;
  FORR(i, 0, n + 1) {
    if (x == 0) break;

    if (x == stages[i]) {  // eat all
      ans += pattys[i];
      break;
    }

    if (x == 1) {
      // B
      break;
    }

    assert(i > 0);

    if (x <= 1ll + stages[i - 1]) {  // Pを含まない下半分よりxが小さかったら
      x--; //xとiが減った次のループへ
    } else { //パティ以上の場合
      ans += 1ll + pattys[i - 1];
      x -= 1ll + stages[i - 1] + 1ll;
    }
  }

  cout << ans << endl;
}
