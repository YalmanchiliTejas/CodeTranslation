#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) int(a.size())
#define clr(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int inf=1e9;
const ll Inf=1e18;
const int N=110;
const int mod=1e9+7;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
template<typename T> bool chkmax(T &a,T b) { return a<b?a=b,1:0; };
template<typename T> bool chkmin(T &a,T b) { return a>b?a=b,1:0; };
int add(int a,int b) { return a+b>=mod?a+b-mod:a+b; }
int sub(int a,int b) { return a-b<0?a-b+mod:a-b; }
void inc(int &a,int b) { a=(a+b>=mod?a+b-mod:a+b); }
void dec(int &a,int b) { a=(a-b<0?a-b+mod:a-b); }
int n,a[N],f[N][N][2];
vector<pii> line[N];
int qpow(int a,int b) {
    int ret=1;
    while(b) {
        if(b&1) ret=1ll*ret*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return ret;
}
void solve(int l,int r,int h) {
    if(l>r) return;
    int mn=inf+1,k=0;
    for(int i=l;i<=r;i++) if(chkmin(mn,a[i])) k=i;
    //cerr<<l<<" "<<r<<" "<<qpow(2,mn-h)<<endl;
    line[r].pb(mp(l,qpow(2,mn-h)));
    solve(l,k-1,mn),solve(k+1,r,mn);
}
int main() {
    n=gi();
    for(int i=1;i<=n;i++) a[i]=gi();
    solve(1,n,1);
    if(line[1].empty()) f[1][1][0]=f[1][1][1]=1;
    else f[1][1][0]=f[1][1][1]=line[1][0].se;
    for(int i=1;i<n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<2;k++) {
                if(!f[i][j][k]) continue;
                int nxt=f[i][j][k];
                for(pii x:line[i+1]) if(x.fi>=j) nxt=1ll*nxt*x.se%mod;
                inc(f[i+1][j][k^1],nxt);
                nxt=f[i][j][k];
                for(pii x:line[i+1]) if(x.fi>=i+1) nxt=1ll*nxt*x.se%mod;
                inc(f[i+1][i+1][k],nxt);
            }
    int ans=0;
    for(int j=1;j<=n;j++)
        for(int k=0;k<2;k++) inc(ans,f[n][j][k]);
    printf("%d\n",ans);
    return 0;
}
