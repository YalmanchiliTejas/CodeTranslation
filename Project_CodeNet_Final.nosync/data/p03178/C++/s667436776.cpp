#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int D = 101;
const int mod = 1e9 + 7;

int dp[N][D][3];
int d;
int lim;
string k;

inline int add(int a, int b, int mod) {
  return (a % mod + b % mod) % mod;
}

inline int add(int a, int b) {
  a += b;
  if(a >= mod) a -= mod;
  if(a < 0) a += mod;
  return a;
}

inline int rec(int cur, int sum, int is_eq){
  if(cur == lim) {
    if(is_eq == 2 && !sum) return -1;
    else return 0;
  }
  int& csi = dp[cur][sum][is_eq];
  if(csi != -1) return csi;
  csi = 0;
  int x = k[cur] - '0';
  for(int i = 0; i <= 9; ++i) {
    int sx = add(sum, i, d);
    int send = is_eq;
    if(((is_eq == 1) && i > x) || (is_eq == 2)) send = 2;
    else if((is_eq == 1) && (i == x)) send = 1;
    else send = 0;
    csi = add(csi, add(rec(cur + 1, sx, send), (sx == 0)));
  }
  return csi;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  cin >> k;
  cin >> d;
  int ans = 0;
  lim = k.size();
  int x = k[0] - '0';
  int sx;
  for(int i = 1; i < x; ++i) {
    sx = i % d;
    ans = add(ans, add(rec(1, sx, 0), (sx == 0)));
  }
  sx = x % d;
  ans = add(ans, add(rec(1, sx, 1), (sx == 0)));
  for(int i = x + 1; i <= 9; ++i) {
    sx = i % d;
    ans = add(ans, add(rec(1, sx, 2), (sx == 0)));
  }
  cout << ans << "\n";
}