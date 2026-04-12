#include<bits/stdc++.h>
using namespace std;
namespace mine
{
    typedef long long ll;
    #define pr pair<ll,ll>
    #define FR first
    #define SE second
    #define MP make_pair
    #define PB push_back
    #define vc vector
    #define all(x) (x).begin(),(x).end()
    #define sz(x) ((int)(x).size())
    #define bin(x) (1ll<<(x))
    ll qread()
    {
        ll ans=0,f=1;char c=getchar();
        while(c<'0' or c>'9') {if(c=='-')f=-1;c=getchar();}
        while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
        return ans*f;
    }
    void write(ll num)
    {
        if(num<0) putchar('-'),num=-num;
        if(num>=10) write(num/10);
        putchar('0'+num%10);
    }
    void write1(ll num){write(num);putchar(' ');}
    void write2(ll num){write(num);putchar('\n');}
    template<typename T> void chmax(T &x,const T y) {x=(x>y?x:y);}
    template<typename T> void chmin(T &x,const T y) {x=(x<y?x:y);}
    ll gcd(ll x,ll y){return y?gcd(y,x%y):0;}

    const int INF=0x3f3f3f3f;
    const int MOD=998244353;
    inline int mm(const int x){return x>=MOD?x-MOD:x;}
    inline ll qpower(ll x,ll e)
    {
        ll ans=1;
        while(e){if(e&1)ans=ans*x%MOD;x=x*x%MOD;e>>=1;}
        return ans;
    }
    ll invm(ll x){return qpower(x,MOD-2);}
    const int N=1e5+10;

	char mp[20][20];bool vis[40][40];
	int n,m;
	bool check(int x,int y)
	{
		vis[x][y]=1;
		if(x==n and y==m) return 1;
		int a=(mp[x+1][y]=='#');
		int b=(mp[x][y+1]=='#');
		if(a+b==1) return check(x+a,y+b); else return 0;
	}
	void main()
	{
		n=qread(),m=qread();
		for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
		if(mp[1][1]=='.' or !check(1,1)) {puts("Impossible");return;}
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!vis[i][j] and mp[i][j]=='#')
			{puts("Impossible");return;}
		puts("Possible");
	}
};
int main()
{
	mine::main();
}