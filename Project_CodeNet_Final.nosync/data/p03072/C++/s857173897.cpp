#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i > 0; i++)

using ll=long long;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int hmax=0;
  int n;
  cin >> n;
  int ans = 0;
  rep(i,n) {
    int h = 0;
    cin >> h;
    hmax = max(hmax, h);
    if(h == hmax) ans++;
  }
  cout << ans << endl;
}