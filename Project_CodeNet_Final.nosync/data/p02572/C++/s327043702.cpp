#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_rev(i, n) for (int i = n-1; i >= 0; i--)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N;
ll A[200020];
ll B[200020];
ll MOD = 1000000007;

int main(){
  cin >> N;
  rep(i, N) cin >> A[i];

  ll ans = 0;
  B[N-1] = A[N-1];
  rep_rev(i, N){
    B[i-1] = (B[i] + A[i-1]) % MOD;
  }

  rep(i, N-1){
    ans += (A[i] * B[i+1]) % MOD;
  }

  cout << ans % MOD << endl;
}
