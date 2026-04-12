#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define gcd __gcd
#define in(a) scanf("%d",&a)
#define in2(a,b) scanf("%d%d",&a,&b)
#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define read(v,i,n) for(i=0;i<n;i++)in(v[i])
#define sc(ch) scanf("%c",&ch)
#define sstr(str) scanf("%s",str)
#define pr(n) printf("%d ",n)
#define out(n) printf("%d\n",n)
#define inl(a) cin >> a
#define prl(a) cout << a << " "
#define outl(a) cout << a << endl
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
#define tddd tuple<double,double,double>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<int,pair<int,int> > >
#define vvii vector<vector<pair<int,int> > >
#define lp(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define N 3002
typedef long long int ll;
int vis[N][N];
ll dp[N][N];
ll v[N];
ll fun(int a,int b)
{
    if(a==b)
        return v[a];
    if(vis[a][b])
        return dp[a][b];
    vis[a][b]=1;
    dp[a][b]=max(v[a]-fun(a+1,b),v[b]-fun(a,b-1));
    return dp[a][b];
}
int main()
{
    int n,i;
    in(n);
    rep(i,n)
        inl(v[i]);
    outl(fun(0,n-1));
}




