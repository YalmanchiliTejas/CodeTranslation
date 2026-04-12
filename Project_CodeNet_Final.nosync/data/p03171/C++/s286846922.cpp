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

int N;
ll A[3005], DP[3005][3005];
bool visited[3005][3005];

ll Solve(int L, int R, bool turn){
  if (L > R) return 0;
  if (visited[L][R]) return DP[L][R];

  visited[L][R] = true;
  if (turn){
    ll ans = Solve(L+1, R, false) + A[L];
    ans = max(ans, Solve(L, R-1, false) + A[R]);
    return DP[L][R] = ans;
  }else{
    ll ans = Solve(L+1, R, true) - A[L];
    ans = min(ans, Solve(L, R-1, true) - A[R]);
    return DP[L][R] = ans;
  }
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  cout << Solve(0, N-1, true) << endl;

  return 0;
}
