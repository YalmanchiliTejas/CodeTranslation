#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll res = 0;

  while (1) {
    sort(a.begin(), a.end(), greater<ll>());
    if (a[0] < n) break;
    ll x = a[0] / n;
    a[0] %= n;
    for (int i = 1; i < n; i++) a[i] += x;
    res += x;
  }
  cout << res << endl;
  return 0;  
} 