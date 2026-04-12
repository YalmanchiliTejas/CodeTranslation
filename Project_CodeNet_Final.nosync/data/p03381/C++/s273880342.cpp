#include <bits/stdc++.h>

using namespace std;

void hawawa()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& i : a) {
    cin >> i;
  }
  auto b = a;
  sort(b.begin(), b.end());
  for (auto&& i : a) {
    if (b[n / 2] <= i) {
      cout << b[n / 2 - 1] << "\n";
    } else {
      cout << b[n / 2] << "\n";
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  hawawa();
  return 0;
}