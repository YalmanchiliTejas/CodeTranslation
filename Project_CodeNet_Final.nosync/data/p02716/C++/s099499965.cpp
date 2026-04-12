#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <map>
#define MOD1 1000000007
#define MOD2 998244353
#define LIMIT1 200002
#define LIMIT2 500002
typedef long long ll;
typedef long double ld;
typedef const void cv;
#define rep(i,n) for(i=0;i<n;i++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define zt(a,b) (max((a),(b))-min((a),(b)))
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll nPr(int n,int r){ll i,result=1;rep(i,r){result*=(ll)(n-i);}return result;}
ll nCr(int n,int r){ll i,result=1;if(n<r) return 0;rep(i,min(r,n-r)){result*=(ll)(n-i);result/=(ll)(i+1);}return result;}
#define fact(n) nPr((int)(n),(int)(n))
#define nHr(n,r) nCr((int)((n)+(r)+1),(int)(r))
#define sankaku(x) (((x)*((x)+1))/2)
int dx[8]={1,0,-1,0,1,-1,-1,1};
int dy[8]={0,1,0,-1,1,1,-1,-1};
int upint(const void *a, const void *b) { return *(int *)a < *(int *)b ? -1 : *(int *)a > *(int *)b ? 1 : 0; }
int downint(const void *a, const void *b) { return *(int *)a < *(int *)b ? 1 : *(int *)a > *(int *)b ? -1 : 0; }
int upchar(const void* left, const void* right) {return strcmp((char *)left,(char *)right);}
int downchar(const void* left, const void* right) {return strcmp((char *)right,(char *)left);}
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
void initialize(){
    
}
int main(void){
  initialize();
  ll n,m,i,j,k,result=0;
  ll a[LIMIT2]={0};
  std::map<ll,ll> dp[LIMIT1];
  char s[LIMIT1];
  
  scanf("%lld",&n);
  rep(i,n) scanf("%lld",&a[i]);
  
  dp[0][0]=0;
  dp[1][0]=0;
  dp[1][1]=a[0];
  for(i=2;i<=n;i++){
    dp[i][(i/2)-1]=max(dp[i-1][(i/2)-1],dp[i-2][(i/2)-2]+a[i-1]);
    dp[i][(i/2)]=max(dp[i-1][(i/2)],dp[i-2][(i/2)-1]+a[i-1]);
    dp[i][(i/2)+1]=dp[i-2][(i/2)]+a[i-1];
  }
  result = dp[n][n/2];
  printf("%lld",result);
  
  return 0;
}

