/*Remember: The Struggle is Important*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     ld           long double
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     pii          pair<int,int>
#define     F            first
#define     S            second
#define     makep        make_pair
#define     maket        make_tuple
#define     show(x)      for(auto c:x)cout<<c<<" ";cout<<"\n";
#define     show2(x)     for(auto c:x)cout<<c.F<<" "<<c.S<<"\n";

const int inf=1e18,M=1e9+7;
const int N=3e3+5;

int dp[N][N][2];        // (l, r, chance)

vector<int> v;
int n;

int rec(int l,int r,int chance)
{
    if(l>r)
        return 0;

    if(dp[l][r][chance]!=inf)
        return dp[l][r][chance];

    int res=0;

    if(chance==0)
        res=max(v[l]+rec(l+1,r,1),v[r]+rec(l,r-1,1));
    else
        res=min(-v[l]+rec(l+1,r,0),-v[r]+rec(l,r-1,0));

    return (dp[l][r][chance]=res);
}

void solve()
{
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
            dp[i][j][0]=dp[i][j][1]=inf;
    }

    cin>>n;

    v.resize(n);
    for(int i=0;i<n;++i)
        cin>>v[i];

    int ans=rec(0,n-1,0);
    cout<<ans;
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        //cout<<"\n";
    }

    return 0;
}

