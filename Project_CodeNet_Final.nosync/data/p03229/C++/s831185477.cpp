#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

ll run(vector<ll> b) {
  ll sum = 0;
  rep(i,sz(b)-1) sum += abs(b[i+1] - b[i]);
  return sum;
}

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  
  ll res = 0;

  vector<ll> b(n);
  if (n%2 == 0) {
    rep(i,n/2) b[i*2+1] = a[i];
    rep(i,n/2) b[i*2] = a[i+n/2];
    res = run(b);
  } else {
    rep(i,n/2) b[i*2+1] = a[i];
    b[n-1] = a[n/2];
    rep(i,n/2) b[i*2] = a[i+n/2+1];
    res = max(res,run(b));

    b[0] = a[n/2];
    rep(i,n/2) b[i*2+2] = a[i];
    rep(i,n/2) b[i*2+1] = a[i+n/2+1];
    res = max(res,run(b));
  }
  cout << res << endl;
  return 0;
}