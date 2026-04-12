#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int n, h, mh, c = 1;
  cin >> n >> mh;
  REP(i, n - 1) {
    cin >> h;
    if (h >= mh) ++c;
    mh = max(h, mh);
  }
  cout << c << endl;
  return 0;
}