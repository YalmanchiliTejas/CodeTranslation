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

int N; ll X;
ll P[51], sum[51];

ll Solve(int L, ll turn){
  if (turn == sum[L]) return P[L];
  if (turn <= 1) return 0;
  
  if (turn == sum[L-1] + 2) return P[L-1] + 1;
  if (turn > sum[L-1] + 2) return P[L-1] + 1 + Solve(L-1, turn - sum[L-1] - 2);
  return Solve(L-1, turn-1);
}

int main(){
  cin >> N >> X;
  P[0] = 1; sum[0] = 1;
  for (int i = 1; i <= N; i++){
    P[i] = P[i-1] * 2 + 1;
    sum[i] = sum[i-1] * 2 + 3;
  }
  cout << Solve(N, X) << endl;
  
  return 0;
}
