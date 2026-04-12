#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(int i = 1; i < (int)(n); i++)
typedef long long ll;
#define NP next_permutation
#define MP make_pair
#define INT_MAX 1e9

int dp[100];

//最大公約数
int gcd(int x, int y){
  if(x % y == 0) return 1;
  return gcd(y, x % y);
}
//最小公倍数
int lcm(int x, int y){
  return x * y / gcd(x, y);
}
//フィボナッチ数列
//配列dpを-1で初期化する
int fib(int n){
  if(n == 0 || n == 1) return dp[n] = 1;
  if(dp[n] != -1) return dp[n];
  return dp[n] = fib(n - 1) + fib(n - 2);
}
//階乗計算(factorial)
int fact(int n){
  if(n = 1) return 1;
  return n * fact(n - 1);
}
//累乗計算(Exponentiation)
//x**y
ll expo(int x, int y){
  ll ans = 1;
  rep(i, y){
    ans *= x;
  }
  return ans;
}
//桁数
int keta(ll x){
  if(x == 0) return 1;
  int res = 0;
  while(x){
    x /= 10;
    res++;
  }
  return res;
}


int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  int mx = h[0];
  int cnt = 0;
  rep(i, n){
  	if(h[i] >= mx) {
  		cnt ++ ;
  		mx = h[i];
  	}
  }
  cout << cnt << endl;
}


/*





















*/
  