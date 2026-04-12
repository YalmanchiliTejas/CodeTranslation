#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define gcd __gcd
#define in(a) scanf("%d",&a)
#define in2(a,b) scanf("%d%d",&a,&b)
#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define read(v,i,n) for(i=0;i<n;i++)in(v[i])
#define twod(mat,i,j,n,m) rep(i,n){rep(j,m)in(mat[i][j]);}
#define sc(ch) scanf("%c",&ch)
#define sstr(str) scanf("%s",str)
#define pr(n) printf("%d ",n)
#define out(n) printf("%d\n",n)
#define llin(a) cin >> a
#define llpr(a) cout << a << " "
#define llout(a) cout << a << endl
#define yes printf("YES\n")
#define no printf("NO\n")
#define lin printf("\n")
#define dbg(v,i,n) for(i=0;i<n;i++)pr(v[i]); lin
#define ck printf("continue\n")
#define all(vec) vec.begin(),vec.end()
#define asc(vec) sort(vec.begin(),vec.end())
#define lower(v,k) lower_bound(v.begin(),v.end(),k)-v.begin()
#define upper(v,k) upper_bound(v.begin(),v.end(),k)-v.begin()
#define tf(mytuple) get<0>(mytuple)
#define ts(mytuple) get<1>(mytuple)
#define tt(mytuple) get<2>(mytuple)
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int> >
#define vvii vector<vector<pair<int,int> > >
#define lp(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define M 1000000007
#define N 200005  //check the limits, man
// read the constraint properly (ll vs int)
typedef long long int ll;
ll const H = 1e15;
ll sum[N];
vvii ad(N);
ll ar[4*N],lazy[4*N];
int lft(int p)
{
    return 2*p;
}
int rht(int p)
{
    return 2*p+1;
}
void process(int l,int h,int p)
{
    if(lazy[p]!=0)
    {
        ar[p]+=lazy[p];
        if(l!=h)
            lazy[lft(p)]+=lazy[p],lazy[rht(p)]+=lazy[p];
        lazy[p]=0;
    }
    return ;
}
void update(int a,int b,ll x,int l,int h,int p)
{
    if(a>h || b<l)
        return ;
    if(a<=l && b>=h)
    {
        lazy[p]+=x;
        return ;
    }
    process(l,h,p);
    int m=(l+h)>>1;
    update(a,b,x,l,m,lft(p));
    update(a,b,x,m+1,h,rht(p));
    ar[p]=max(ar[lft(p)]+lazy[lft(p)],ar[rht(p)]+lazy[rht(p)]);
    return ;
}
ll query(int a,int b,int l,int h,int p)
{
    if(a>h || b<l)
        return -H;
    if(a<=l && b>=h)
        return ar[p]+lazy[p];
    process(l,h,p);
    int m=(l+h)>>1;
    return max(query(a,b,l,m,lft(p)),query(a,b,m+1,h,rht(p)));
}
int main()
{
    int n,m,l,r,a,i,j;
    in2(n,m);
    while(m--)
    {
        in3(l,r,a);
        sum[l]+=a;
        ad[r].pb({l,-a});
    }
    ll ans=0;
    ll x;
    for(i=1;i<=n;i++)
    {
        update(0,i-1,sum[i],0,n,1);
        x=query(0,i-1,0,n,1);
        ans=max(ans,x);
        update(i,i,x,0,n,1);
        m=ad[i].size();
        rep(j,m)
            update(0,ad[i][j].F-1,ad[i][j].S,0,n,1);
    }
    llout(ans);
}
