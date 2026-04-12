#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 6000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int dp[maxn+5][maxn+5];
int a[maxn+5],nxt[maxn+5],last[maxn+5];
int n,ans;

int eq(int x,int y,int z) {return a[x]==a[y] && a[x]==a[z];}

void upd(int &x,int y) {if(x<y) x=y;}

void trans(int x,int y,int now)
{
    if(now>n) return;
    if(now==n) {upd(ans, dp[x][y] + eq(x,y,now)); return;}
    int A=dp[x][y];
    upd(dp[now+1][now], A + eq(x,y,now+2));
    upd(dp[now+2][now], A + eq(x,y,now+1));
    upd(dp[now+2][now+1], A + eq(x,y,now));

    upd(dp[now][x], A + eq(y,now+1,now+2));
    upd(dp[now+1][x], A + eq(y,now,now+2));
    upd(dp[now+2][x], A + eq(y,now,now+1));
    
    upd(dp[now][y], A + eq(x,now+1,now+2));
    upd(dp[now+1][y], A + eq(x,now,now+2));
    upd(dp[now+2][y], A + eq(x,now,now+1));
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n*3) scanf("%d",&a[i]);
    int N=1,base=0; vi tmp;
    tmp.pb(a[1]); tmp.pb(a[2]);
    rep(i,1,n-1) if(!(a[i*3]==a[i*3+1] && a[i*3+1]==a[i*3+2])) N++,tmp.pb(a[i*3]),tmp.pb(a[i*3+1]),tmp.pb(a[i*3+2]); else base++;
    tmp.pb(a[n*3]);
    assert(N*3==(int)tmp.size());
    n=0;
    for(auto x: tmp) a[++n]=x;
    memset(last,63,sizeof last);
    per(i,1,n) nxt[i]=last[a[i]],last[a[i]]=i;

    //rep(i,1,n) rep(j,1,i-1) dp[i][j]=-inf;
    dp[2][1]=0;
    rep(x,1,n) rep(y,1,x-1) 
    {
        trans(x,y,x/3*3+3);
        if(nxt[x]/3*3>x/3*3) trans(x,y,nxt[x]/3*3);
        if(nxt[y]/3*3>x/3*3) trans(x,y,nxt[y]/3*3);
    }
    printf("%d\n",base+ans);
    return 0;
}