#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  int mh = 0;
  int cnt = 0;
  rep(i, n) {
    int h;
    cin >> h;
    if(h >= mh) {
      ++cnt;
      mh = h;
    }
  }
  cout << cnt << endl;
  return 0;
}