#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()
#define let auto const

int main() {
  i64 n;
  while(cin >> n, n) {
    vector<i64> a(n);
    rep(i,0,n) cin >> a[i];
    sort(all(a));
    i64 sum = 0;
    rep(i,1,n-1) sum +=a[i];
    cout << sum / (n - 2) << endl;
  }
}

