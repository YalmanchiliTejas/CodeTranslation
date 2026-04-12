#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <iomanip>


using namespace std;


typedef long long ll;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);

  int maxH = 0;
  int N;
  cin >> N;
  int curH;
  int ans = 0;
  for (int i = 1 ; i <= N ; i++) {
    cin >> curH;
    if (curH >= maxH) {
      ans++;
      maxH = curH;
    }
  }

  cout << ans;


  return 0;
}


