#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define all(s) s.begin(), s.end()

int main(int argc, char** argv) {
  int n;
  cin >> n;
  uint64_t a[n];
  rep(i, n) cin >> a[i];

  vector<int> sorted; // contains max values. sorted.

  rep(i, n) {
    auto it = lower_bound(all(sorted), a[i]);

    if (it == sorted.begin()) {  // The lowest
      sorted.insert(sorted.begin(), a[i]);  // Push front
    } else {
      --it;
      *it = a[i];
    }
  }

  cout << sorted.size() << endl;
}