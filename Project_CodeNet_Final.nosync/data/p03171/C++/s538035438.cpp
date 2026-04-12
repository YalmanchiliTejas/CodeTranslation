#include "bits/stdc++.h"
#define _USE_MATH_DEFINES
#include <math.h>
 
using namespace std;
 
using LL = long long;
using VLL = std::vector<LL>;
using VVLL = std::vector<VLL>;
using VVVLL = std::vector<VVLL>;
using LD = long double;
using VLD = std::vector<LD>;
using VVLD = std::vector<VLD>;
using VVVLD = std::vector<VVLD>;
 
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }

//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define ALL(v) v.begin(), v.end()
#define PRINTLN(v) {LL i=0; for(auto (a): v ){   cerr <<i << " : "<<  a << endl; i++;}}
#define PRINTSP(v) for(auto (a): v ) {cerr << a << " ";} cerr << endl
#define cmax(a,b) {if(a<b){a=b;}}
#define cmin(a,b) {if(a>b){a=b;}}
#define EACH(a,A) for(auto a: A)
//#define cmax(a,b) a = (a>b ? a:b)
//#define cmin(a,b) a = (a<b ? a:b) 
//cin,cout高速化のおまじない＋桁数指定
inline VLL cinvll(LL N){
  VLL A(N);
  REP(i,N){
    cin >> A[i];
  }
  return move(A);
}
struct Fast{
	Fast(){
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast;

LL nCr(LL n, LL r) {
  LL num = 1;
  for (LL i = 1; i <= r; i++) {
    num = num * (n - i + 1) / i;
  }
  return num;
}


void func(){
  LL N;
  cin >> N;
  auto A = cinvll(N);

  VVLL dp(N+1,VLL(N+1,0));

  for(LL len =1; len<=N;len++){
    for(LL i=0; i+len<=N;i++){
      LL j=i+len;
      if((N-len)%2==0){
        dp[i][j] = max(dp[i+1][j]+A[i],dp[i][j-1]+A[j-1]);
      }
      else{
        dp[i][j] = min(dp[i+1][j]-A[i],dp[i][j-1]-A[j-1]);
      }
    }
  }
  cout << dp[0][N];

  


} 
int main()
{
  func();
  return 0;
}
 