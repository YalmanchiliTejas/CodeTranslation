#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll n;

/* add your algorithm here */

int main() {
  cin >> n;
  vector<ll> a;
  rep(i,n) {
    ll t; cin >> t;
    a.pb(t);
  }

  ll si = a.size();
  vector<ll> ans(si, 0);
  
  ll cnt1, cnt2;
  if (si % 2 == 1) {
    ans[si/2] = a[0];
    cnt1 = si/2-1, cnt2 = si/2 + 1;
    for (ll i = 1; i < si; ++i) {
      if (i % 2 == 0) {
        ans[cnt1--] = a[i];
      } else {
        ans[cnt2++] = a[i];
      }
    }
  } else {
    cnt1 = si/2 - 1, cnt2 = si/2;
    for (ll i = 0; i < si; ++i) {
      if (i % 2 == 1) {
        ans[cnt1--] = a[i];
      } else {
        ans[cnt2++] = a[i];
      }
    }
  }

  for (auto itr : ans) {
    cout << itr << " ";
  }

  cout << endl;
}
