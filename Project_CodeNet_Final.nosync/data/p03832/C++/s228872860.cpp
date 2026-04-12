#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define F first
#define S second
#define pb emplace_back
#define mt make_tuple
#define mp make_pair
#define gcd __gcd
#define PI 3.141592653589
// Input
#define in(a) scanf("%d",&a)
#define in2(a,b) scanf("%d%d",&a,&b)
#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define llin(a) cin >> a
#define inl(a) scanf("%lld",&a)
#define read(v,i,n) for(i=0;i<n;i++)in(v[i])
#define twod(mat,i,j,n,m) rep(i,n){rep(j,m)in(mat[i][j]);}
#define sc(ch) scanf("%c",&ch)
#define sstr(str) scanf("%s",str)
// Output
#define pr(a) printf("%d ",a)
#define pr2(a,b) printf("%d %d\n",a,b)
#define pr3(a,b,c) printf("%d %d %d\n",a,b,c)
#define out(a) printf("%d\n",a)
#define outl(a) printf("%lld\n",a)
#define llpr(a) cout << a << " "
#define llout(a) cout << a << "\n"
#define yes printf("YES\n")
#define no printf("NO\n")
#define lin printf("\n")
// Iterator
#define lp(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define all(vec) vec.begin(),vec.end()
#define lower(v,k) lower_bound(v.begin(),v.end(),k)-v.begin()
#define upper(v,k) upper_bound(v.begin(),v.end(),k)-v.begin()
#define tf(mytuple) get<0>(mytuple)
#define ts(mytuple) get<1>(mytuple)
#define tt(mytuple) get<2>(mytuple)
// Debug
#define dbg(v,i,n) for(i=0;i<n;i++)pr(v[i]); lin
#define what(x) cerr << #x << " : " << x << "\n"
#define ck printf("continue\n")
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}
// Data Type
#define ll long long int
#define ii pair<int,int>
#define pli pair<ll,int>
#define triple tuple<int,int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int> >
#define vvii vector<vector<pair<int,int> > >
#define M 1000000007
#define N 1005  //check the limits, man
const ll INF = 1e18;
ll dp[N][N];
ll pro(ll a,ll b)
{
    return (a*b)%M;
}
ll power(ll a,ll b)
{
    ll x=1;
    a%=M;
    while(b>0)
    {
        if(b&1)
            x=pro(x,a);
        b=b>>1;
        a=pro(a,a);
    }
    return x;
}
ll fact[N],inv[N],finv[N];
void buildfact()
{
    int i,q,r;
    fill(fact,fact+N,1);
    fill(inv,inv+N,1);
    fill(finv,finv+N,1);
    for(i=2;i<N;i++)
    {
        fact[i]=pro(fact[i-1],i);
        q=M/i,r=M%i;
        inv[i]=M-pro(q,inv[r]);
        finv[i]=pro(finv[i-1],inv[i]);
    }
    return ;
}
ll choose(int n,int r)
{
    return pro(fact[n],pro(finv[r],finv[n-r]));
}
ll fun(int rem,int i,int f)
{
    return pro(choose(rem,i*f),pro(fact[i*f],pro(power(finv[i],f),finv[f])));
}
int main()
{
    int n,i,j,f,a,b,c,d;
    in(n);
    in2(a,b);
    in2(c,d);
    buildfact();
    dp[a-1][0]=1;
    for(i=a;i<=b;i++)
    {
        rep(j,n+1)
        {
            dp[i][j]=dp[i-1][j];
            for(f=c;f<=d;f++)
            {
                if(i*f>j)
                    break;
                dp[i][j]+=pro(dp[i-1][j-i*f],fun(n-j+i*f,i,f));
            }
            dp[i][j]%=M;
        }
    }
    llout(dp[b][n]);
}


