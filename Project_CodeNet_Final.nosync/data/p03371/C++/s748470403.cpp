#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//　ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const int mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int gcd(int a, int b){
  if (b==0) return a;
  else return gcd(b,a%b);
}


// ll memo[2020][2020];
// int pascal_triangle(){
//   for(int i = 0; i < 1000; i++){
//     for(int j = 0; j < i+1; j++){
//       if(j == 0 || j == i) memo[i][j] = 1;
//       else{
// 	memo[i][j] = (memo[i-1][j-1]+memo[i-1][j])%mod;
//       }
//     }
//   }
//   return 0;
// }


// int factorial(int n){
//   if(n == 0) return 1;
//   return n*factorial(n-1);
// }

// int divisor(int a){
//   int cnt = 0;
//   for(int i=1; i <= a; i++) if(a%i == 0) cnt++;
//   return cnt;
// }

// int comb(int n, int k){
//   pascal_triangle();
//   return memo[n][k];
// }

// int cans(bool f){
//   if(f) cout << "Yes" << endl;
//   else cout << "No" << endl;
//   return 0;
// }







//二項係数(mod剰余)----------------------------

// const int MAX = 3000010;
// const int M = 1000000007;

// vector<ll> fac(MAX); //n!(mod M)
// //a,bの範囲的にこれだけ配列を用意していけば十分
// vector<ll> ifac(MAX); //k!^{M-2} (mod M)

// ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
//     ll ans = 1;
//     while(n != 0){
//         if(n&1) ans = ans*x % M;
//         x = x*x % M;
//         n = n >> 1;
//     }
//     return ans;
// }

// ll COMinit(){
//   //大した量ではないので，先にfax[i]とifax[i]を全て計算しておく
//   fac[0] = 1;
//   ifac[0] = 1;
//   for(ll i = 0; i<MAX; i++){
//     fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
//     ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
//   }
//   return 0;
// }

// ll COM(ll a, ll b){ //aCbをmod計算
//   if(a == 0 && b == 0)return 1;
//   if(a < b || a < 0)return 0;
//   ll tmp = ifac[a-b]* ifac[b] % M;
//   return tmp * fac[a] % M;
// }

//-----------------------------------------

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >>Y;
  int ans = inf;
  for(int i=max(Y,X);i>=0;i--){
    ans = min(ans,2*i*C+A*max(0,X-i)+B*max(0,Y-i));
  }
  cout << ans << endl;
 
  return 0;
}








