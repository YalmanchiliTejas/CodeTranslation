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
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int> >
#define vvii vector<vector<pair<int,int> > >
#define lp(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define N 200005
typedef long long int ll;
ll fact[N],inv[N],finv[N];
ll pro(ll a,ll b)
{
    return (a*b)%M;
}
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
ll ncr(int a,int b)
{
    if(a<b)
        return 0;
    return pro(fact[a],pro(finv[b],finv[a-b]));
}
int main()
{
    int n,m,k;
    in3(n,m,k);
    buildfact();
    ll ans=pro(ncr(m+1,3),pro(n,n))+pro(ncr(n+1,3),pro(m,m));
    ans=pro(ans,ncr(n*m-2,k-2));
    outl(ans);
}
