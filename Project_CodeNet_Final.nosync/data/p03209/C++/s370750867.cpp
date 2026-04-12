#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;

ll n , x;
ll a[55], p[55]; ///バーガーの厚さと含まれるパティの数を入れる配列


ll dfs(ll N, ll X){
  if (N == 0) return 1;
  else if (X <= N) return 0;
  else if (X <= 1 + a[N-1]) return dfs(N-1, X-1);
  else if (X == 2 + a[N-1])  return p[N-1] + 1;
  else return p[N-1] + 1 + dfs(N-1, X-a[N-1]-2);
}

int main() {
  cin >> n >> x;

  a[0] = 1;
  p[0] = 1;
  rep(i, n) a[i + 1] = 2 * a[i] + 3;
  rep(i, n) p[i + 1] = 2 * p[i] + 1;
  ll ans = dfs(n, x);

  cout << ans << endl;


}
