#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  int ans = 0;
  cin >> n;

  int mh = 0;
  for (int i = 0; i < n; ++i)  {
    int h;
    cin >> h;
    if (mh <= h) {
      ans++;
    }
    mh = max(mh, h);
  }

  cout << ans << "\n";
  return 0;
}