#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int main() {
  cin.sync_with_stdio(false);

  int r, g, b;
  cin >> r >> g >> b;

  int n = r * 100 + g * 10 + b;

  if (n % 4 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}