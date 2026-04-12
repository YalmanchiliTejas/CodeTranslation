#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <map>

#define fir first
#define sec second
#define sz(s) (s).size();
#define pb push_back
#define get(n) scanf("%d",&n);
#define gets(s) string s;cin >> (s);
#define prfi(n) printf("%d", &n);
#define prfd(n) printf("%lf", &n);
#define All(s) (s).begin(), (s).end()
#define rep(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define rep0(i,j) for(int (i)=0;(i)<(j);(i)++)
#define repdown(i, j, k) for(int (i)=(j);(i)>=(k);(i)--)
#define repdown0(i,j) repdown(i,j,0)
#define dump(x)  std::cout << #x << " = " << (x) << std::endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using ll = long long;
using vi = std::vector<int> ;
using vvi = std::vector<vi> ;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vd = std::vector<double> ;
using vvd = std::vector<vd> ;
using qi = std::queue<int> ;
using vpii = std::vector<std::pair<int, int> >;
using namespace std;

const int Mod = (1e9) + 7;
const int max_n = 3 * (1e3) + 1;
const int max_m = 83 * (1e5) + 1;
const int INF = 10241024;
long double INFD = 100100100;

//_____________________________________Templates_________________________________________//

template<class T1, class T2> inline void chmin(T1 &a, T2 b){if(a > b) a = b;}
template<class T1, class T2> inline void chmax(T1 &a, T2 b){if(a < b) a = b;}

//mainly use for dynamic prog
template<class T1, class T2>
void update(T1 &a, T2 b){
  a += b;
  if(a > Mod) a %= Mod;
}

inline void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

inline void OUT(void){
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

//_____________________array calc____________________________________//
/*
vvi mul(vvi &A, vvi &B){
  vvi C(A.size(), vi(B.size()))
  rep(i,A.size()){
    rep(j,B.size()){
      rep(k,B[0].size()){
        C[i][j] = (C[i][j] A[i][k] + B[k][j]) % Mod;
      }
    }
  }

  return C;
}

vvi pow(vvi A, ll n){
  vvi B(A.size(), vi(A.size()));
  rep(i=0;i<A.size();i++){
    B[i][i] = 1;
  }

  while (n >0){
    if (n & 1) B = mul(B, A);
    A = mul(A, A);
    n = n >> 1;
  }
  return B;
}
*/
//_____________________Bynary Indexed Tree __________________________//
/*
const max_st = (1 << 15) - 1;
int bit[max_st];
int sum (int i){
  int s = 0;
  while(i > 0){
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x){
  while(i <= n){
    bit[i] += x;
    i += i & -i;
  }
}
*/
//_____________________　following sorce code_________________________//
int n;
vll a(max_n);
vvll dp(max_n, vll(max_n));



int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;IN(n);
  rep0(i,n)IN(a[i]);

  rep(len,1,n){
    for(int i=0;i+len<=n;i++){
      int j = i+len;
      if( (n - len)%2 == 0)dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
      else dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
    }
  }
  OUT(dp[0][n]);
  return 0;
}