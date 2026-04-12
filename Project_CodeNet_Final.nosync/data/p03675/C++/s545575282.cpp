#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) FOR(i, n, 0);

signed main () {
  cin.tie(0);
  cout << setprecision(10);

  int n; cin >> n;
  vector<int> a(n);
  
  REP(i, n) {
    cin >> a[i];
  }

  vector<int> odd, even;
  REP(i, n) {
    if(i % 2 == 1) {
      even.pb(a[i]);
    } else {
      odd.pb(a[i]);
    }
  }

  if(n % 2 == 1) {
    reverse(odd.begin(), odd.end());
    REP(i, odd.size()) {
      cout << odd[i] << " ";
    }
    REP(i, even.size()) {
      cout << even[i] << " ";
    }
    cout << endl;
  } else {
    reverse(even.begin(), even.end());
    REP(i, even.size()) {
      cout << even[i] << " ";
    }
    REP(i, odd.size()) {
      cout << odd[i] << " ";
    }
    cout << endl;
  }
  
}
