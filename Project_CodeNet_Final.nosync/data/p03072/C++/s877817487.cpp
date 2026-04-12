#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto&& e : h) cin >> e;
  int x = -1;
  int cnt = 0;
  for (auto&& e : h) {
    if (e >= x) {
      cnt++;
      x = e;
    }
  }
  cout << cnt << endl;
}
