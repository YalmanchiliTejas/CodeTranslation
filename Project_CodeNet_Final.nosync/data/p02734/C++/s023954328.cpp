#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll mod = 998244353;
  int N, S; cin >> N >> S;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector< vector<ll> > dp1(S+1, vector<ll>(3, 0));
  vector< vector<ll> > dp2(S+1, vector<ll>(3, 0));
  dp1[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= S; j++) {
      if (A[i] <= j) {
        dp2[j][0] = dp1[j][0];
        dp2[j][1] = (dp1[j][1]+dp1[j-A[i]][1]+dp1[j-A[i]][0]*(i+1)%mod)%mod;
        dp2[j][2] = (dp1[j][2]+dp1[j-A[i]][1]*(N-i)%mod+dp1[j-A[i]][0]*(i+1)%mod*(N-i)%mod)%mod;
      } else {
        for (int k = 0; k < 3; k++) dp2[j][k] = dp1[j][k];
      }
    }
    dp1 = dp2;
  }
  cout << dp1[S][2] << endl;
}
