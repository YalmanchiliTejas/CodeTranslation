#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ignore ignore
#define pb emplace_back
#define mt make_tuple
#define gcd __gcd
#define bitcount(x)  __builtin_popcount(x)
#define bitcountll(x)  __builtin_popcountll(x)
// Input
#define in(a) scanf("%d",&a)
#define in2(a,b) scanf("%d%d",&a,&b)
#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp(p) in2(p.F,p.S)
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
#define prp(p) pr2(p.F,p.S)
#define out(a) printf("%d\n",a)
#define outl(a) printf("%lld\n",a)
#define llpr(a) cout << a << " "
#define llout(a) cout << a << "\n"
#define pinttwod(mat,i,j,n,m) rep(i,n){rep(j,m)pr(mat[i][j]);   lin;}
#define plltwod(mat,i,j,n,m)  rep(i,n){rep(j,m)llpr(mat[i][j]); lin;}
#define byes printf("YES\n")
#define bno printf("NO\n")
#define yes printf("Yes\n")
#define no printf("No\n")
#define lin printf("\n")
// Iterator
#define rep(i,n) for(i=0;i<n;++i)
#define fone(i,n) for(i=1;i<=n;++i)
#define rrep(i,n) for(i=n-1;i>=0;--i)
#define lp(i,a,b) for(i=a;i<b;++i)
#define rlp(i,a,b) for(i=a;i>=b;--i)
#define all(vec) vec.begin(),vec.end()
#define lower(v,k) lower_bound(v.begin(),v.end(),k)-v.begin()
#define upper(v,k) upper_bound(v.begin(),v.end(),k)-v.begin()
#define tf(mytuple) get<0>(mytuple)
#define ts(mytuple) get<1>(mytuple)
#define tt(mytuple) get<2>(mytuple)
// function
#define sz(x) x.size()
#define inrange(i,a,b) (i>=a && i<=b)
#define FLUSH fflush(stdout)
#define precision(x) cout << setprecision(x) << fixed
#define remax(a,b) a=max(a,b)
#define remin(a,b) a=min(a,b)
#define lchild(p) 2*p
#define rchild(p) 2*p+1
#define lseg l,m,2*p
#define rseg m+1,h,2*p+1
#define bhardo(mat,i,j,n,m,t) rep(i,n){rep(j,m)mat[i][j]=t;}
#define biton(mask,i)  (mask&(1<<i))
#define bitoff(mask,i) (!(mask&(1<<i)))
// Debug
#define dbg(v,i,n) for(i=0;i<n;i++)pr(v[i]); lin
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
// Constant
const double PI = acos(-1);
const double eps = (1e-9);
const ll INF = 1e18;
const int M = (1e9)+7;
const int N = (1e6)+5;  // check the limit, man
void solve()
{
    int n,i;
    in(n);
    vector<ll> v(n);
    rep(i,n)
        llin(v[i]);
    ll k=0;
    ll x,a;
    while(1)
    {
        x=0;
        rep(i,n)
            x+=(v[i]/n);
        if(x==0)
            break;
        k+=x;
        rep(i,n)
            a=(v[i]/n),v[i]=v[i]-n*a+(x-a);
    }
    llout(k);
}
int main()
{
    int t=1;
//    in(t);
    while(t--)
        solve();
}






