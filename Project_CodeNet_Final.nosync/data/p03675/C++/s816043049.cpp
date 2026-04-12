#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

void reverse(vector<int>& as)
{
  int l = 0;
  int u = as.size() - 1;
  while (l < u) {
    swap(as[l], as[u]);
    ++l;
    --u;
  }
}

void dump(int n)
{
  vector<int> as;
  as.reserve(n);
  for (int i = 1; i <= n; ++i) {
    as.push_back(i);
    reverse(as);
  }
  for (const auto& a: as) cout << a << " ";
  cout << endl;
}

int main()
{
  int n;
  cin >> n;
  vector<int> as;
  as.reserve(n);
  for (int i = 0; i <n ; ++i) {
    int a;
    cin >> a;
    as.push_back(a);
  }
  bool first = true;
  for (int i = n; i > 0; i -= 2) {
    if (first) {
      first = false;
    } else {
      cout << " ";
    }
    cout << as[i-1];
  }
  for (int i = n % 2 ? 2 : 1; i <= n; i += 2) cout << " " << as[i-1];
  cout << endl;
  return 0;
}