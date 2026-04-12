#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 2020;
int n, A[maxn * 3];

int tag, val[maxn], dp[maxn][maxn];

void solve() {
  cin>>n;
  rep(i,1,3*n){
    A[i]=read();
  }
  if(n==1){
    puts(A[1]==A[2]&&A[2]==A[3]?"1":"0");
    return;
  }
  int mx=0;
  memset(dp,-0x3f,sizeof dp);
  memset(val,-0x3f,sizeof val);
  rep(x,1,5)rep(y,1,5)if(x!=y){
    int flg=1;
    int lst=-1;
    rep(i,1,5)if(i!=x&&i!=y)flg&=lst==-1||A[i]==lst,lst=A[i];
    dp[A[x]][A[y]]=flg;
    dp[A[y]][A[x]]=flg;
    chkmax(mx,flg),chkmax(val[A[x]],flg),chkmax(val[A[y]],flg);
  }
  rep(T, 2, n - 1) {
//    puts("-----");
//    rep(i,1,n)rep(j,1,n)printf("(%d %d) %d\n",i,j,dp[i][j]<0?-1:dp[i][j]);
    int ttt = 3 * (T - 1) + 2;
    int x = A[ttt + 1];
    int y = A[ttt + 2];
    int z = A[ttt + 3];
    if (x == y && y == z) {
      tag++;
      continue;
    }
    if(y==z)swap(x,z);
    if(x==z)swap(y,z);
    static int tmp[maxn];
    if(x==y){
      rep(i,1,n)tmp[i]=dp[i][x];
    }
    int orz=0;
    int v1=max(mx,dp[z][z]+1);
    int v2=max(mx,dp[y][y]+1);
    int v3=max(mx,dp[x][x]+1);
    rep(i,1,n){
      chkmax(orz,val[i]);
      chkmax(dp[i][x],val[i]);
      chkmax(dp[x][i],val[i]);
      chkmax(dp[i][y],val[i]);
      chkmax(dp[y][i],val[i]);
      chkmax(dp[i][z],val[i]);
      chkmax(dp[z][i],val[i]);
      if(x==y){
        chkmax(dp[i][z],tmp[i]+1);
        chkmax(dp[z][i],tmp[i]+1);
      }
    }
    chkmax(dp[x][y],v1);
    chkmax(dp[y][x],v1);
    chkmax(dp[x][z],v2);
    chkmax(dp[z][x],v2);
    chkmax(dp[y][z],v3);
    chkmax(dp[z][y],v3);
    if(x==y)rep(i,1,n){
      chkmax(val[z],tmp[i]+1),chkmax(val[i],tmp[i]+1),chkmax(mx,tmp[i]+1);
    }
    chkmax(val[x],max(orz,max(v1,v2)));
    chkmax(val[y],max(orz,max(v1,v3)));
    chkmax(val[z],max(orz,max(v2,v3)));
    chkmax(mx,max(val[x],max(val[y],val[z])));
  }
//  puts("-----");
//  rep(i,1,n)rep(j,1,n)printf("(%d %d) %d\n",i,j,dp[i][j]<0?-1:dp[i][j]); puts("");
  int res=0;
  rep(x,1,n)rep(y,1,n){
    chkmax(res,dp[x][y]+(x==y&&A[3*n]==x));
  }
  cout<<res+tag<<endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}