#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  vector<ll> sort_a = A;
  sort(sort_a.begin(), sort_a.end());
  reverse(sort_a.begin(), sort_a.end());
  ll ans = 0;
  if (N % 2 == 0) {
    for (ll i = 0; i < N / 2; ++i) {
      ans += 2 * sort_a.at(i);
    }
    for (ll i = N / 2; i < N; ++i) {
      ans -= 2 * sort_a.at(i);
    }
    ans -= sort_a.at(N / 2 - 1);
    ans += sort_a.at(N / 2);
  }
  else {
    //sbs
    for (ll i = 0; i < N / 2; ++i) {
      ans += 2 * sort_a.at(i);
    }
    for (ll i = N / 2; i < N; ++i) {
      ans -= sort_a.at(i) * 2;
    }
    for (ll i = 0; i < 2; ++i) {
      if (i + N / 2 >= N) {
        continue;
      }
      ans += sort_a.at(i + N / 2);
    }

    //bsb
    ll temp = 0;
    for (ll i = 0; i < N / 2 + 1; ++i) {
      temp += sort_a.at(i) * 2;
    }
    for (ll i = N / 2 + 1; i < N; ++i) {
      temp -= sort_a.at(i) * 2;
    }
    for (ll i = 0; i < 2; ++i) {
      temp -= sort_a.at(N / 2 - i);
    }
    // cout << ans << ' ' << temp << endl;
    ans = max(ans, temp);
  }
  cout << ans << endl;
}
