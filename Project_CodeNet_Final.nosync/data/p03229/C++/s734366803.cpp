#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;

int main() {
  int N; cin>>N;
  vector<ll> a(N);
  REP(i,N) cin>>a[i];
  sort(a.begin(), a.end());
  ll ans = 0;
  if(N % 2 == 0) {
    for(int i = 1; i < N/2; i++) {
      ans += (ll)(i*2)*abs(a[i] - a[i-1]);
      ans += (ll)(i*2)*abs(a[N-1-i] - a[N-i]);
    }
    ans += (ll)(N-1)*abs(a[N/2]-a[N/2-1]);
  } else {
    for(int i = 1; i <= N/2; i++) {
      ans += (ll)(i*2)*abs(a[i] - a[i-1]);
      ans += (ll)(i*2)*abs(a[N-1-i] - a[N-i]);
    }
    ll work = min(abs(a[N/2]-a[N/2-1]),	a[N/2+1]-a[N/2]);
    ans -= work;

  }
  cout << ans << endl;
  return 0;
}
