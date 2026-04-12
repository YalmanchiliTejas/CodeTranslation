#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
  int N; cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];

  sort(all(A));

  vector<ll> ansm(N), ansp(N);
  rep(i,N) {
    if (i == 0) ansm[i] = A[(N+1) / 2 - 1]; // 端はマイナスで一番大きいの
    else if (i % 2 == 1) ansm[i] = A[N - (i+1) / 2]; // 大きい方からつめてく
    else ansm[i] = A[i / 2 - 1]; // 小さい方からつめてく
  }
  rep (i,N) {
    if (i == 0) ansp[i] = A[N / 2];
    else if (i % 2 == 1) ansp[i] = A[i / 2];
    else ansp[i] = A[N - i / 2];
  }

  ll big,small;
  big = small = 0;
  rep(i,N) {
    if (i == 0) continue;
    big += abs(ansp[i] - ansp[i-1]);
    small += abs(ansm[i] - ansm[i-1]);
  }

  cout << max(big,small) << endl;
}