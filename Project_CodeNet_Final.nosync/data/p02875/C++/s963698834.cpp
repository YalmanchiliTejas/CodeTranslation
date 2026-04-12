#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define F first
#define S second
#define eb emplace_back
#define pb emplace_back
#define mt make_tuple
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
#define state tuple<int,int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int> >
#define vvii vector<vector<pair<int,int> > >
#define M 998244353
#define B 300  //check the limits, man
#define N 5000003
const ll INF = 1e18;
ll inv[N];
ll pro(ll a,ll b)
{
    return (a*b)%M;
}
void buildfact()
{
    int i,q,r;
    fill(inv,inv+N,1);
    for(i=2;i<N;i++)
    {
        q=M/i,r=M%i;
        inv[i]=M-pro(q,inv[r]);
    }
    return ;
}
int main()
{
    buildfact();
    int i,n,m;
    ll ans,p2,p3,temp;
    in(n);
    ans=0,p2=1,p3=1;
    m=(n>>1),temp=1;
    rep(i,m)
    {
        ans+=pro(temp,p2);
        p2+=p2;
        if(p2>M)p2-=M;
        temp=pro(temp,pro(n-i,inv[i+1]));
    }
    rep(i,n)
        p3=pro(p3,3);
    ans+=ans;
    ans%=M;
    p3=(p3+M-ans)%M;
    llout(p3);
}
