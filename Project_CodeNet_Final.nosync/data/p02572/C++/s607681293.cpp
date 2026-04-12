#include"stdio.h"
#include"string.h"
#include"stack"
#include"map"
#include"math.h"
#include"iostream"
#include"vector"
#include"queue"
#include"algorithm"
using namespace std;
#define OK printf("\n");
#define Debug printf("this_ok\n");
#define INF 1e18
typedef long long ll;
#define scanll(a,b) scanf("%lld%lld",&a,&b);
#define scanl(a) scanf("%lld",&a);
#define printl(a,b) if(b == 0) printf("%lld ",a); else printf("%lld\n",a);
#define print_int(a,b) if(b == 0) printf("%d ",a); else printf("%d\n",a);
typedef pair<int,int> PII;

inline int read(){
    int s = 0, w = 1; char ch = getchar();
    while(ch < '0' || ch > '9')   { if(ch == '-') w = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { s = (s << 3) + (s << 1) + (ch ^ 48); ch = getchar(); }
    return s * w;
}
const ll mod = 1e9+7;
const int N = 500010,M = 300010;
const  double pi = acos(-1);
const int inf = 1 << 29;
const int dirx[4] = {-1,0,1,0};

char str[N],t[N];
int a[N];
ll sum[N];
int main(){
  int n = read();
  for(int i = 1; i <= n; i++) a[i] = read();
  for(int i = n; i >= 1; i --){
     sum[i] = sum[i + 1] + a[i];
     sum[i] %= mod;
  }
  ll ans = 0;
  for(int i = 2; i <= n; i ++){
     ans = ans + a[i - 1] * sum[i] % mod;
     ans %= mod;
  }
  printf("%lld\n",ans);
}
/*
3
1 2 3
2
2 6
*/

