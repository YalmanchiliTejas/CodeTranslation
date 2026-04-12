#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int cache;
    cin >> cache;
    if (a.size() == 0 || cache <= a.at(a.size() - 1)) {
      a.push_back(cache);
    } else {
      int lower_bound = 0, upper_bound = a.size();
      while (lower_bound < upper_bound - 1) {
        int half = (lower_bound + upper_bound) / 2;
        if (cache <= a.at(half - 1)) {
          lower_bound = half;
        } else {
          upper_bound = half;
        }
      }
      a.at(lower_bound) = cache;
    }
  }
  cout << a.size() << endl;
}
