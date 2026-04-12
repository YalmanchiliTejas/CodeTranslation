#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define F first
#define S second
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
#define triple tuple<int,int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int> >
#define vvii vector<vector<pair<int,int> > >
#define M 998244353
#define N 200005
ll pro(ll a,ll b)
{
    ll temp=a;
    temp*=b;
    return temp;
}
int main()
{
    int n,i,j,a,b,x,y,l,r;
    in(n);
    vii vp(n);
    rep(i,n)
    {
        in2(a,b);
        if(a>b)
            swap(a,b);
        vp[i]={a,b};
    }
    sort(all(vp));
    vi Min(n);
    vi Max(n);
    vector<int> diff(n);
    Min[0]=vp[0].S,Max[0]=Min[0];
    lp(i,1,n)
        Min[i]=min(Min[i-1],vp[i].S),Max[i]=max(Max[i-1],vp[i].S);
    ii temp;
    rep(i,n)
    {
        tie(l,r)=vp[i];
        diff[i]=(1e9);
        if(Min[i]>=l)
        {
            y=vp[n-1].F;
            if(i>0)
                y=max(y,Max[i-1]);
            temp={r,r};
            j=lower(vp,temp);
            if(j>0 && Min[j-1]>=r)
                diff[i]=max(y,Max[j-1])-r;
            diff[i]=min(diff[i],y-l);
        }
    }
    //dbg(diff,i,n);
    ll ans=(1e18);
    ans=min(ans,pro(vp[n-1].F-vp[0].F,Max[n-1]-Min[n-1]));
    rep(i,n)
        ans=min(ans,pro(Max[n-1]-vp[0].F,diff[i]));
    llout(ans);
}




