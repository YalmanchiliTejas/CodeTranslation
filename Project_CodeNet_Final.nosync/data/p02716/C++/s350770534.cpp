#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
#define int ll
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const ld eps = 1e-9;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<55;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n; cin >> n;
  vll a(n);
  ll su = 0;
  for(int i=0;i<n;++i) {
    cin >> a[i];
    su += a[i];
  }

  ll su1 = 0, su2 = 0;
  for(int i=0;i<n;++i) {
    if(i%2 == 0) su1 += a[i];
    else su2 += a[i];
  }

  if(n%2 == 0) {
    vll sul(n), sur(n);
    for(int i=0;i<n;i++) {
      if(i == 0) {
        sul[i] = a[0];
        continue;
      }
      if(i%2 == 0) {
        sul[i] = sul[i-1] + a[i];
      } else {
        sul[i] = sul[i-1];
      }
    }
    for(int i=n-1;i>=0;--i) {
      if(i== n-1) {
        sur[i] = a[i];
        continue;
      }
      if(i%2 == 0) {
        sur[i] = sur[i+1];
      } else {
        sur[i] = sur[i+1] + a[i];
      }
    }

/*     printv(sul1);
    printv(sul2);
    printv(sur1);
    printv(sur2); */


    ll su = -LINF;
    for(int i=1;i<n-1;++i) {
      if(i%2 == 1) su = max(su, sul[i] + sur[i+1]);
      //else if(i != n-2) su = max(su, sul2[i] + sur1[i+2]);
    }
    su = max(su, max(sul[n-1], sur[0]));
    cout << su << endl;
    return 0;
  }

  if(n == 3) {
    cout << max(a[0], max(a[1], a[2])) << endl;
    return 0;
  }

  vll sul1(n+2), sur1(n+2), sul2(n+2), sur2(n+2);
  for(int i=0;i<n;++i) {
    if(i%2 == 0) {
      sul1[i+1] = sul1[i] + a[i];
      sul2[i+1] = sul2[i];
    } else {
      sul1[i+1] = sul1[i];
      sul2[i+1] = sul2[i] + a[i];
    }
  }

  for(int i=n-1;i>=0;--i) {
    if(i%2 == 0) {
      sur1[i+1] = sur1[i+2] + a[i];
      sur2[i+1] = sur2[i+2];
    } else {
      sur1[i+1] = sur1[i+2];
      sur2[i+1] = sur2[i+2] + a[i];
    }
  }

/*   printv(sul1);
  printv(sul2);
  printv(sur1);
  printv(sur2); */

  ll ans = LINF;
  for(int i=0;i<n;++i) {
    if(i%2 == 0) {
      ans = min(ans, sul1[i+1] + sur2[i+2]);
      //if(i != n-1) ans = min(ans, sul1[i+1] + sur1[i+3]);
    } else {
      ans = min(ans, sul2[i+1] + sur1[i+2]);
      //if(i != n-1) ans = min(ans, sul2[i+1] + sur2[i+3]);
    }
  }
  ans = su - ans;

  for(int i=0;i<n;++i) {
    if(i%2 == 0) ans = max(ans, su1 - a[i]);
  }

  vvll dpl(n/2, vll(2));
  dpl[0][0] = a[0];
  dpl[0][1] = a[1];
  for(int i=1;i<n/2;++i) {
    dpl[i][0] = dpl[i-1][0] + a[i*2];
    dpl[i][1] = max(dpl[i-1][0] + a[i*2+1], dpl[i-1][1] + a[i*2+1]);
  }

  vvll dpr(n/2, vll(2));
  dpr[n/2-1][0] = a[n-1];
  dpr[n/2-1][1] = a[n-2];
  for(int i=n/2-2;i>=0;--i) {
    //cout << i*2+1 << " " << i*2+2 << endl;
    dpr[i][0] = dpr[i+1][0] + a[i*2+2];
    dpr[i][1] = max(dpr[i+1][0] + a[i*2+1], dpr[i+1][1] + a[i*2+1]);
  }

  //cout << ans << endl;

  for(int i=0;i<n/2;++i) {
    if(i == 0) ans = max(ans, a[i*2+1] + max(dpr[i+1][0], dpr[i+1][1]));
    else if(i == n/2-1) ans = max(ans, max(dpl[i-1][0], dpl[i-1][1]) + a[i*2+1]);
    else ans = max(ans, max(dpl[i-1][0], dpl[i-1][1]) + a[i*2+1] + max(dpr[i+1][0], dpr[i+1][1]));
    //cout << i << " " << ans << endl;
  }


  cout << max(su2, ans) << endl;
}
