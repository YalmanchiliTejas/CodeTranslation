#include <iostream>
#include <string>
using namespace std;
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <set>
#include <map>
#define MOD1 1000000007
#define MOD2 998244353
#define LIMIT1 200010
#define LIMIT2 500010
#define LIMIT3 1000010
#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef long double ld;
typedef const void cv;
typedef pair<ll,ll> P;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define per(i,n) for((i)=(n)-1;(i)>=0;(i)--)
template<class T,class C> T max(T a,C b){ return ((a)>(T)(b) ? (a) : (T)(b)); }
template<class T,class C> T min(T a,C b){ return ((a)<(T)(b) ? (a) : (T)(b)); }
#define zt(a,b) (max((a),(b))-min((a),(b)))
#define setpre(n) fixed << setprecision(n)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[8]={1,0,-1,0,1,-1,-1,1},dy[8]={0,1,0,-1,1,1,-1,-1};
int upint(cv *a, cv *b) { return *(int *)a < *(int *)b ? -1 : *(int *)a > *(int *)b ? 1 : 0; }
int downint(cv *a, cv *b) { return *(int *)a < *(int *)b ? 1 : *(int *)a > *(int *)b ? -1 : 0; }
int upchar(cv *left, cv *right) {return strcmp((char *)left,(char *)right);}
int downchar(cv *left, cv *right) {return strcmp((char *)right,(char *)left);}
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
int main(void){
  initialize();
  ll n,m,i,j,k,result=0,x,sum=0;
  ll a[LIMIT2]={0};
  string s;
  ll dp[LIMIT1]={0},dp2[LIMIT1]={0};
  
  cin >> n >> x >> m;
  a[0] = x;
  rep(i,m) dp[i]=-1;
  dp[x] = 0;
  
  ll tmp = x;
  sum = x;
  dp2[0] = x;
  bool looped = false;
  for(i=1;i<n;i++){
    tmp = modpow(a[i-1],2,m);
    sum += tmp;
    a[i] = tmp;
    dp2[i] = sum;
    if(looped) continue;
    if(dp[tmp] != -1){//m回以内に必ずある
      k = i-dp[tmp];//循環発見
      //cout << i << " " << k << endl;
      tmp = (n-1-i)/k;//ループが何回あるか
      sum += tmp * (sum-dp2[i-k]);//循環部分の合計
      n -= tmp*k;
      looped = true;
    }else{
      dp[tmp] = i;
    }
  }
  result = sum;
  
  cout << result << endl;
  return 0;
}
