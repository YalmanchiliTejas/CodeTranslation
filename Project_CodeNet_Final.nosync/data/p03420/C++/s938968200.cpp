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

ll N, K;

int main(){
  cin >> N >> K;
  if (K == 0){
    cout << N * N << endl;
    return 0;
  }

  ll ans = 0;
  for (ll b = K + 1; b <= N; b++){
    ans += (N / b) * (b - 1 - K + 1);
    if (N % b >= K){
      ans += (N % b) - (K - 1);
    }
  }
  cout << ans << endl;

  return 0;
}
