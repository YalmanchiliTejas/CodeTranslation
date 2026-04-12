#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int D, N;
string S;
ll DP1[int(1e4+5)][105], DP2[int(1e4+5)][105];

int main(){
  cin >> S >> D;
  N = S.length();
  DP2[0][0] = 1;

  for (int i = 1; i <= N; i++){
    for (int j = 0; j < D; j++){
      for (int k = 0; k < 10; k++){
        DP1[i][(j+k)%D] += DP1[i-1][j];
        DP1[i][(j+k)%D] %= MOD;
      }
    }

    int now = S[i-1] - '0';
    for (int j = 0; j < D; j++){
      for (int k = 0; k < now; k++){
        DP1[i][(j+k)%D] += DP2[i-1][j];
        DP1[i][(j+k)%D] %= MOD;
      }
    }

    for (int j = 0; j < D; j++){
      DP2[i][(j+now) % D] = DP2[i-1][j];
    }
  }

  ll ans = DP1[N][0] + DP2[N][0] - 1;
  ans %= MOD; if (ans < 0) ans += MOD;
  cout << ans << endl;

  return 0;
}
