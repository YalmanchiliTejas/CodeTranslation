/*pata hai na?*/

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

const ld pi=acos(-1);
const int inf=1e18,M=1e9+7;
const int N=110;

int dp[N][5][2];

string s;

int rec(int ind,int k,int tight)
{
    if(k<0)
        return 0;

    if(ind==0)
    {
        if(k==0)
            return 1;
        return 0;
    }

    if(dp[ind][k][tight]!=-1)
        return dp[ind][k][tight];

    int x=s[ind-1]-'0';
    int mx=(tight==1)?x:9;

    int res=0;
    int nt;

    for(int i=0;i<=mx;++i)
    {
        if(i==x)
            nt=tight;
        else
            nt=0;

        res+=rec(ind-1,k-(i!=0),nt);
    }

    return (dp[ind][k][tight]=res);
}

void solve()
{
    mem(dp,-1);

    int k;
    cin>>s>>k;

    int n=s.length();
    reverse(all(s));

    int ans=rec(n,k,1);
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


