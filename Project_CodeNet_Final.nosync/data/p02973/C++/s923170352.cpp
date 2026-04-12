#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> color;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    auto itr = lower_bound(color.begin(), color.end(), a, greater_equal<int>());
    if (itr == color.end())
      color.push_back(a);
    else
      *itr = a;
  }
  cout << color.size() << endl;
}
