#pragma region
#include <bits/stdc++.h>
using namespace std;
inline void ci(void){
  return;
}
template <typename First, typename... Rest>
void ci(First& first, Rest&... rest){
  cin >> first;
  ci(rest...);
  return;
}
inline void co(void){
  cout << endl;
  return;
}
template <typename First, typename... Rest>
void co(First first, Rest... rest){
  cout << first << "";
  co(rest...);
  return;
}
#define ll long long
#define ld long double
#define st string
#define wh while
#define ve vector
#define mp make_pair
#define tp tuple
#define mt make_tuple
#define pb push_back
#define pof pop_front
#define pob pop_back
#define pf push_front
#define fr front
#define ft first
#define sc second
#define tos to_string
#define len length
#define rt return
#define br break
#define con continue
#define lcm(n, m) (n * m / gcd(n, m))
#define np next_permutation
#define repi(i, m, n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i, n) repi(i, 0, n)
#define repill(i, m, n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define repll(i, n) repill(i, 0, n)
#define revi(i, m, n) for(int i=(int)(m);i>(int)(n);i--)
#define rev(i, m) revi(i, m, 0)
#define revill(i, m, n) for(ll i=(ll)(m);i>(ll)(n);i--)
#define revll(i, n) revill(i, 0, n)
#define sz(v) ((int)(v).size()) 
#define each(i, n) for(auto&& i: n)
#define all(n) (n.begin(), n.end())
#define allr(n) (n.rbegin(), n.rend())
#define sp(n) cout << fixed << setprecision(n)
#define inf pow(10, 9)
#pragma endregion
// sqrt ルート, int 2*10^9, gcd　最大公約数
// __builtin_popcount bitの個数

ve<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

int N, M;

int dfs(int x, ve<bool> &B, ve<ve<bool>> &A){
  bool f = 1;
  rep(i, N){
    if(B.at(i) != 1){
      f = 0;
    }
  }
  if(f){
    rt 1;
  }
  int a = 0;
  rep(i, N){
    if(A.at(x).at(i) == 0){
      con;
    }
    if(B.at(i)){
      con;
    }
    B.at(i) = 1;
    a += dfs(i, B, A);
    B.at(i) = 0;
  }
  rt a;
}

int main() {
  ci(N, M);
  ve<ve<bool>> A(N, ve<bool>(N, 0));
  rep(i, M){
    int a, b;
    ci(a, b);
    a--, b--;
    A.at(a).at(b) = 1;
    A.at(b).at(a) = 1;
  }
  ve<bool> B(N, 0);
  B.at(0) = 1;
  co(dfs(0, B, A));
  rt 0;
}