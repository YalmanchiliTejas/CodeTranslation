#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  ll A[N]; rep(i,N) cin >> A[i];
  sort(A,A+N);

  ll result = 0;
  if (N%2==0) {
    ll r[N] = {};
    rep(i,N/2) {
      r[i*2] = A[(N/2-1)-i];
      r[(N-1)-i*2] = A[N/2+i];
    }
    rep(i,N-1) result += abs(r[i+1]-r[i]);
  }
  else {
    ll r1[N] = {}, r2[N] = {};
    ll res1 = 0, res2 = 0;
    rep(i,N/2-1) r1[(i+1)*2] = A[i];
    r1[0] = A[N/2-1]; r1[N-1] = A[N/2];
    rep(i,N/2) r1[i*2+1] = A[N/2+1+i];
    rep(i,N-1) res1 += abs(r1[i+1]-r1[i]);

    rep(i,N/2-1) r2[(i+1)*2] = A[(N-1)-i];
    r2[0] = A[N/2+1]; r2[N-1] = A[N/2];
    rep(i,N/2) r2[i*2+1] = A[(N/2-1)-i];
    rep(i,N-1) res2 += abs(r2[i+1]-r2[i]);
    result = max(res1, res2);
    // rep(i,N) cout << r1[i] << " "; cout << endl;
    // rep(i,N) cout << r2[i] << " "; cout << endl;
  }
  cout << result << endl;
  return 0;
}