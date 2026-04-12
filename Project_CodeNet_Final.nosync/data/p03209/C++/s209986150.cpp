#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, j, k) for (int i = j; i < k; i++)
#define REP(i, j) FOR(i, 0, j)
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

vll num, nump;

ll rec(ll N, ll X) {

  if (N == 0) {
    return X <= 0 ? 0 : 1;
  } else if (X <= 1 + num[N - 1]) {
    return rec(N - 1, X - 1);
  } else {
    return nump[N - 1] + 1 + rec(N - 1, X - 2 - num[N - 1]);
  }

}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  ll N, X;
  cin >> N >> X;

  num.push_back(1);
  nump.push_back(1);
  for (int i = 1; i <= 50; i++) {
    num.push_back(num[i - 1] * 2LL + 3LL);
    nump.push_back(nump[i - 1] * 2LL + 1LL);
  }
  
  // cout << num[N] << endl;
  // cout << nump[N] << endl;

  cout << rec(N, X) << endl;
  return 0;
}
