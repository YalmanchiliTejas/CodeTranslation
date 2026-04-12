#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sz(a) ((int)(a).size())
#define rep(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define dec(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define clr(a,v) memset(a, v, sizeof(a))
#define all(a) (a).begin(),(a).end()
#define MAXN 1010
#define N 1010
#define LOGN 20
#define buli(x) (__builtin_popcountll(x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
const ll mod = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define int long long
int a, b, c, d, n;
ll fat[N], ifat[N], mat[N][N];
int dp[N][N], dp2[N][N];
void pre(){
    rep(i,0,MAXN){
        mat[i][0]=mat[i][i]=1;
        rep(j,0,i){
            mat[i][j]=(mat[i-1][j]+mat[i-1][j-1])%mod;
        }
    }
}

ll comb(int x, int y){
    return mat[x][y]%mod;
}

ll solve2(int qt, int t){
    if(qt == 1) return 1;
    if(dp2[qt][t]!=-1)return dp2[qt][t];
    ll ans =0;
    ans = (solve2(qt-1,t)*comb(qt*t, t))%mod;
    ans%=mod;
    return dp2[qt][t]=ans;
}

int solve(int p, int t){
    if(p == 0)return 1;
    if(t >b)return 0;
    if(dp[p][t]!=-1)return dp[p][t];
    ll ans=0;
    ans += solve(p,t+1);
    ans%=mod;
    for (int i = c; i <= d && i * t <= p; i++){
        ll temp = solve(p - (i * t), t + 1) %mod;
        temp = (temp * comb(p,t*i))%mod;
        temp = (temp * solve2(i, t))%mod;
        temp = (temp * ifat[i])%mod;
        ans = (ans + temp)%mod;
    }
    return dp[p][t]=ans;
}

int32_t main()
{
    fat[0]=1; 
    rep(i,1,MAXN)fat[i]= (fat[i-1]*i)%mod;
    rep(i,0,MAXN)ifat[i]=powmod(fat[i],mod-2);
    gn(n); gn(a);gn(b);gn(c);gn(d); 
    pre();
    clr(dp, -1);
    clr(dp2, -1);
    printf("%lld\n", solve(n, a));
    return 0;
}










































