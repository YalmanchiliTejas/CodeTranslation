#include <bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<(x)<<endl
typedef long long ll;
template<class T> inline void chmax(T& a, T b) {
  if (a < b) a = b;
}

template<class T> inline void chmin(T& a, T b) {
  if (a > b) a = b;
}
const int MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int X;
  cin >> X;
  if (X == 3 || X == 5 || X == 7) COUT("YES");
  else COUT("NO");
}