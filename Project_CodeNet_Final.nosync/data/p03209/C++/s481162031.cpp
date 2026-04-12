#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <map>
#define MOD1 1000000007
#define MOD2 998244353
#define LIMIT1 200002
#define LIMIT2 500002
typedef long long ll;
typedef long double ld;
typedef const void cv;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define per(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define zt(a,b) (max((a),(b))-min((a),(b)))
#define setpre(n) fixed << setprecision(n)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
#define sankaku(x) (((x)*((x)+1))/2)
int dx[8]={1,0,-1,0,1,-1,-1,1},dy[8]={0,1,0,-1,1,1,-1,-1};
int upint(cv *a, cv *b) { return *(int *)a < *(int *)b ? -1 : *(int *)a > *(int *)b ? 1 : 0; }
int downint(cv *a, cv *b) { return *(int *)a < *(int *)b ? 1 : *(int *)a > *(int *)b ? -1 : 0; }
int upchar(cv *left, cv *right) {return strcmp((char *)left,(char *)right);}
int downchar(cv *left, cv *right) {return strcmp((char *)right,(char *)left);}
void tmpInit(int *c,ll m) {ll i;rep(i,m) c[i]=i;}
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1){
      res *= a; if(mod>=1) res %= mod;
    }
    a *= a; if(mod>=1) a %= mod;
    n >>= 1;
  }
  return res;
}
void initialize(){
  
}
map<ll,ll> memo[52];
void level(ll n){
  if(n==0){
    memo[n][0] = 1;
    memo[n][1] = 1;
  }else{
    level(n-1);
    memo[n][0] = 2*memo[n-1][0]+3;
    memo[n][1] = 2*memo[n-1][1]+1;
  }
}
ll patties(ll n,ll x){
  if(memo[n][0]<x) x = memo[n][0];
  if(n==0) return memo[n][1];
  else if(x==1) return 0;
  //cout << n << " "  << x << endl;
  if(memo[n-1][0]+1>=x){
    return patties(n-1,x-1);
  }else if(memo[n-1][0]+2==x){
    return memo[n-1][1]+1;
  }else{
    return memo[n-1][1]+1+patties(n-1,x-memo[n-1][0]-2);
  }
}
int main(void){
  initialize();
  ll n,m,i,j,k,result=0,x;
  int a[LIMIT2]={0};
  string s;
  
  cin >> n >> x;
  level(n);
  result = patties(n,x);
  cout << result << endl;
  
  return 0;
}