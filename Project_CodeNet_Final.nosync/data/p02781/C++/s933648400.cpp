#include<bits/stdc++.h>
#define int            long long
#define ll             long long
#define pb          push_back
#define    endl        '\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define dep(i,a,b)    for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  105

string n;
int k;
int dp[N][5][2];

int rec(int i,int rem,int fl)
{
    if(i==n.size())
        return (rem==0);
    int &res=dp[i][rem][fl];
    if(res!=-1)
        return res;
    res=0;
    res=rec(i+1,rem,(n[i]>'0' or fl));
    if(rem)
    {
        int mx=9;
        if(!fl)
            mx=n[i]-'0';
        int c=rec(i+1,rem-1,1);
        rep(i,1,mx)
        res+=c;
        if(mx!=0)
            res+=rec(i+1,rem-1,fl);
    }
    return res;
}

void solve()
{
    cin>>n>>k;
    memset(dp,-1,sizeof dp);
    int ans=rec(0,k,0);
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}