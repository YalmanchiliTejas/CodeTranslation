/// __Macro's__
#include <bits/stdc++.h>
using namespace std;
#define ll                   long long
#define ld                   long double
#define II                   pair<int,int>
#define III                  pair<int, II>
#define VL                   vector<ll>
#define VI                   vector<int>
#define VII                  vector<II>
#define VIII                 vector<III>
#define VVI                  vector<vector<int>>
#define VVII                 vector<vector<II>>
#define F                    first
#define S                    second
#define mkpr                 make_pair
#define PQ                   priority_queue
#define pb                   push_back
#define eb                   emplace_back
#define all(v)               v.begin(), v.end()
#define LINE                 putc('\n', stdout)
#define SPACE                putc(' ' , stdout)
#define TAB                  putc('\t', stdout)
#define YES                  printf("YES")
#define NO                   printf("NO")
#define Yes                  printf("Yes")
#define No                   printf("No")
#define yes                  printf("yes")
#define no                   printf("no")
#define _0                   printf("0")
#define _1                   printf("-1")
#define msg(x)               printf(#x)
#define nil                  (void)0
#define fillarr(arr, val)    fill((int*)arr, (int*)arr+(sizeof(arr)/sizeof(int)), val)
#define _log2(x)             (31-__builtin_clz(x))
#define INF                  1000000007  //(ll)2e17
#define MOD                  1000000007 
const char IO_MODE = 0; // in-->00<--out | 0: Norm, 1: Fast
#define getint ReadInt()
inline ll ReadInt(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}inline void WriteInt(ll x){char CH[20];
//if(x<0) putchar('-'); x=-x;
int Num=0;if(!x){putchar('0');return;}while(x>0)CH[++Num]=x%10,x/=10;while(Num)putchar(CH[Num--]+48);}
inline void out(int x){if(IO_MODE&1)WriteInt(x);else printf("%i",x);}template<typename...Args>inline
void out(int x,Args...args){out(x);SPACE;out(args...);}inline void in(int &x){if(IO_MODE&2)x=ReadInt();
else scanf("%i",&x);}template<typename...Args>inline void in(int &x,Args&...args){in(x);in(args...);}
/*inline void outll(ll x){if(IO_MODE&1)WriteInt(x);else printf("%lld",x);}template<typename...Args>inline
void outll(ll x,Args...args){outll(x);SPACE;outll(args...);}inline void inll(ll &x){if(IO_MODE&2)x=ReadInt();
else scanf("%lld",&x);}template<typename...Args>inline void inll(ll &x,Args&...args){inll(x);inll(args...);}*/
inline void outll(ll x){if(IO_MODE&1)WriteInt(x);else printf("%I64d",x);}template<typename...Args>inline
void outll(ll x,Args...args){outll(x);SPACE;outll(args...);}inline void inll(ll &x){if(IO_MODE&2)x=ReadInt();
else scanf("%I64d",&x);}template<typename...Args>inline void inll(ll &x,Args&...args){inll(x);inll(args...);}
int aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,mm,nn,oo,pp,qq,rr,ss,tt,uu,vv,ww,xx,yy,zz;
int tc,ty;
#define MAXN 200200
///
int n, A[3003];
ll dp[3003][3003];
int main(){
  in(n);
  for(int i=1 ; i<=n ; i++) in(A[i]);
  for(int j=0 ; j<=n ; j++)
    for(int i=1 ; i+j<=n ; i++){
      if(j%2==n%2) dp[i][i+j] = min(dp[i+1][i+j]-A[i], dp[i][i+j-1]-A[i+j]);
      else         dp[i][i+j] = max(dp[i+1][i+j]+A[i], dp[i][i+j-1]+A[i+j]);
    }
  cout << dp[1][n] << endl;
}