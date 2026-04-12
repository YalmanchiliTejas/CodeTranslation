/*
 *      ┌─┐       ┌─┐ + +
 *   ┌──┘ ┴───────┘ ┴──┐++
 *   │                 │
 *   │       ───       │++ + + +
 *   ███████───███████ │+
 *   │                 │+
 *   │       ─┴─       │
 *   │                 │
 *   └───┐         ┌───┘
 *       │         │
 *       │         │   + +
 *       │         │       Code is far away from bug with the animal protecting
 *       │         └──────────────┐
 *       │                        │
 *       │                        ├─┐
 *       │                        ┌─┘
 *       │                        │
 *       └─┐  ┐  ┌───────┬──┐  ┌──┘  + + + +
 *         │ ─┤ ─┤       │ ─┤ ─┤
 *         └──┴──┘       └──┴──┘  + + + +
 *                神兽保佑
 *               代码无BUG!
 */

#include<bits/stdc++.h>
using namespace std;
class IN{
public:
    template<typename T>
    IN& operator >>(T &x){read(x);return *this;}
    IN& operator >>(double &x){scanf("%lf",&x);return *this;}
    IN& operator >>(char *s){scanf("%s",s);return *this;}
    IN& operator >>(char &c){c=getchar();return *this;}
private:
    template<typename T>
    void read(T &x){
        T f=1;int c=getchar();x=0;
        while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
        while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
        x*=f;
    }
}in;
class NL{}nl;
class BK{}bk;
class OUT{
public:
    template<typename T>
    OUT& operator <<(T x){write(x);return *this;}
    OUT& operator <<(const char *s){printf("%s",s);return *this;}
    OUT& operator <<(char c){putchar(c);return *this;}
    OUT& operator <<(BK x){putchar(' ');return *this;}
    OUT& operator <<(NL x){putchar('\n');return *this;}
private:
    template<typename T>
    void write(T x){
        if(x<0)putchar('-'),x=-x;
        if(x>=10)write(x/10);
        putchar(x%10+48);
    }
}out;

#define pb(x) push_back(x)
#define fi first
#define se second
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,n,a) for(int i=n;i>=a;--i)
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
typedef vector<int> VI;
typedef vector<ll> VL;
/*****************************************************************************************************/
ll Pow(ll a,ll b,ll mod){ll res=1;a%=mod;while(b){if(b&1)(res*=a)%=mod;(a*=a)%=mod;b>>=1;}return res%mod;}
ll inv(ll a,ll p){if(a==1)return 1;return (p-p/a)*inv(p%a,p)%p;}//p为素数,a<p
ll C(ll n,ll m,ll p){ll res=1;for(ll i=1,j=n-m+1;i<=m;++i,++j){res=res*inv(i,p)%p*j%p;}return res;}
/*****************************************************************************************************/
/*ll ask(int x){ll res=0;while(x)res+=c[x],x-=x&-x;return res;}
void add(ll v,int x){while(x<=n)c[x]+=v,x+=x&-x;}*/
const ll p=998244353;
const int N=3000+10;
int a[N];
ll dp[N][N];

int main(){
    int n,s;
    in>>n>>s;
    rep(i,1,n)in>>a[i];
    rep(i,1,n)rep(j,1,s){
        dp[i][j]=dp[i-1][j];
        if(j>a[i])
            dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%p;
        if(j==a[i])
            dp[i][j]=(dp[i][j]+i)%p;
    }
    ll ans=0;
    rep(i,1,n)
        ans=(ans+dp[i][s])%p;
    out<<ans;
    return 0;
}
