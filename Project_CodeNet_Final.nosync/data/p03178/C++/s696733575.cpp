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
#define S 105
#define N 10005  //check the limits, man
// read the constraint properly (ll vs int)
typedef long long int ll;
ll dp[N][S],ar[N][S];
string str;
int n,d;
ll fun(int i,int s)
{
    if(i==n)
        return (s==0);
    if(ar[i][s]>=0)
        return ar[i][s];
    ar[i][s]=0;
    int j;
    for(j=0;j<10;j++)
        ar[i][s]+=fun(i+1,(s+j)%d);
    ar[i][s]%=M;
    return ar[i][s];
}
ll process(int i,int s)
{
    if(i==n)
        return (s==0);
    if(dp[i][s]>=0)
        return dp[i][s];
    dp[i][s]=0;
    int j;
    for(j=0;j<str[i];j++)
        dp[i][s]+=fun(i+1,(s+j)%d);
    dp[i][s]+=process(i+1,(s+j)%d);
    dp[i][s]%=M;
    return dp[i][s];
}
int main()
{
    int i,j;
    llin(str);
    in(d);
    n=str.size();
    rep(i,n)
    {
        str[i]-='0';
        rep(j,d)
            dp[i][j]=-1,ar[i][j]=-1;
    }
    ll ans=-1;
    lp(j,0,str[0])
        ans+=fun(1,j%d);
    ans+=process(1,j%d);
    llout(ans%M);
}

