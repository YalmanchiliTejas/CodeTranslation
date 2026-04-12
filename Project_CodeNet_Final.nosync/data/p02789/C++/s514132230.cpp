#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

#define FALSE printf("false\n");
#define TRUE printf("true\n");
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i = 0;i < ((int)(n));++i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define test(a) cout<<"line:"<<__LINE__<<"["<<(#a)<<": "<<(a)<<"]"<<endl

const int INF = 1e9+7;
const ll INFL = 9*1e18;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

#define SUM(vec) accumulate(all(vec),0LL) // 配列の中身を全部足す
template<typename T>void print(T&& x){cout<<x<<endl;}// 改行付き出力
ll inline digit(ll num){int tmp = 0;while(num){tmp++;num/=10;}return tmp;} // 桁数
template<typename T>inline T digitSum(T num){T sum = 0;while(num){sum+=num%10;num/=10;}return sum;} // 各桁の和
template<typename T>inline T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);} // 最大公約数
template<typename T>inline T lcm(T a, T b){T g = gcd(a,b);return a/g*b;} // 最小公倍数
template<typename T>inline T power(T a,T b){T tmp=1;rep(i,b){tmp*=a;}return tmp;} // 累乗
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
bool isPrime(ll n); // 素数か
vector<ll> primes(ll n); // 素因数分解
int ctoi(char c){return c - '0';}

const ll COM_MAX = (ll)(1e6+100); // combinationの最大値
vector<ll> fac(COM_MAX),finv(COM_MAX),inv(COM_MAX);
void comb_init(); // 初期化
ll comb(ll n,ll k); // nCk


template<typename T>bool isOk(int key,T value){
  return key <= value.fi;
}
template<typename T>T binary_search(vector<pair<int,int>> a,T key){
  T ok = a.size();
  T ng = -1;
  while(abs(ok - ng) > 1){
    T mid = (ok + ng) / 2;
    if(isOk(key,a[mid]))ok = mid;
    else ng = mid;
  }
  return ok;
}


// TODO: write
int main() { 
  int n,m;cin>>n>>m;
  print((n==m)?"Yes":"No");
  return 0;
}




void comb_init(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<COM_MAX;++i){
    fac[i]=fac[i-1]*i%INF;
    inv[i]=INF-inv[INF%i]*(INF/i)%INF;
    finv[i]=finv[i-1]*inv[i]%INF;
  }
}

ll comb(ll n,ll k){
  if(n<k)return 0;
  if(n<0||k<0)return 0;
  return fac[n]*(finv[k]*finv[n-k]%INF)%INF;
}

bool isPrime(ll n) {
	for (int i = 2; n >= i * i; ++i) {
		if(!(n % i))return false;
	}
  return true;
}
vector<ll> primes(ll n){
  vector<ll> v;
  for (ll i = 2; i*i <= n; ++i) {
    while(n%i==0){
      n/=i;
      v.pb(i);
    }
  }
  if(n != 1)v.pb(n);
  return v;
}


/* 二分探索の時に使う
template<typename T>bool isOk(T key,T value){
  return key <= value;
}
template<typename T>T binary_search(vector<T> a,T key){
  T ok = a.size();
  T ng = -1;
  while(abs(ok - ng) > 1){
    T mid = (ok + ng) / 2;
    if(isOk(key,a[mid]))ok = mid;
    else ng = mid;
  }
  return ok;
}
*/