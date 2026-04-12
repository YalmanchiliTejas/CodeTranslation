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
  cout << "\n";
  return;
}
template <typename First, typename... Rest>
void co(First first, Rest... rest){
  cout << first << " ";
  co(rest...);
  return;
}
#define ll long long
#define ld long double
#define st string
#define dl double
#define wh while
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define tp tuple
#define ft first
#define sc second
#define ve vector
#define tos to_string
#define len length
#define rt return 0
#define gcd __gcd
#define lcm(n, m) n * m / gcd(n, m)
#define np next_permutation
#define repi(i, m, n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i, n) repi(i, 0, n)
#define sz(v) ((int)(v).size()) 
#define ea(i, n) for(auto&& i: n)
#define so(n) sort(n.begin(), n.end())
#define sp(n) cout << fixed << setprecision(n)
#pragma endregion
// rtsq ルート, int 2*10^9, __gcd

int main() {
  int N, a = 0, b = 0;
  ci(N);
  ve<int> H(N);
  rep(i, N){
    ci(H.at(i));
  }
  rep(i, N){
    if(b <= H.at(i)){
      b = H.at(i);
      a++;
    }
  }
  co(a);
}