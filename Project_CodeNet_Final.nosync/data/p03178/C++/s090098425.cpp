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
const int N=1e4;

string s;
int d,n;

int dp[N][105][2];          // (index, sum, tight)

int rec(int n,int sum,int tight)
{
    if(n==-1)
    {
        if(sum==0)
            return 1;
        else
            return 0;
    }

    if(dp[n][sum][tight]!=-1)
        return dp[n][sum][tight];

    int k=9;
    if(tight)
        k=s[n]-'0';

    int res=0,nt;
    for(int i=0;i<=k;++i)
    {
        if(i==s[n]-'0')
            nt=tight;
        else
            nt=0;

        res=(res+rec(n-1,(sum+i)%d,nt))%M;
    }

    //cout<<n<<" "<<sum<<" "<<tight<<" "<<res<<"\n";

    return (dp[n][sum][tight]=res);
}

void solve()
{
    mem(dp,-1);

    cin>>s>>d;
    n=s.length();

    reverse(all(s));

    int ans=(rec(n-1,0,1)-1ll+M)%M;
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


