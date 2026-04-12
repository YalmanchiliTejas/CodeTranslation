#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,31)-1;


int main() {
  int N; cin >> N;
  ll a[N]; rep(i,N) cin >> a[i];
  ll result = 0;
  int pos = 0;
  while (true) {
    pos=(pos+1)%N;
    ll tmp = a[pos]/N;
    rep(j,N) { if (j!=pos) a[j]+=tmp; else a[pos]%=N; }
    result += tmp;
    bool ok = true; rep(j,N) if (a[j]>=N) ok = false;
    if (ok) break;
  }
  cout << result << endl;
}