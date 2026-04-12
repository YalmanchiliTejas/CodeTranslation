#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define let auto
#define conr auto const&

int const N = 200 * 1000 + 16;
int const M = 1000 * 1000 * 1000 + 7;

int n, m;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  cin >> n;
  deque<int> a;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if(i&1)
      a.emplace_front(x);
    else
      a.emplace_back(x);
  }

  if(n&1)
    reverse(a.begin(), a.end());

  for(int x : a)
    cout << x << " ";
  cout << flush;
}