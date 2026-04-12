#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a-1;i>=b;i--)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define SP(x) setprecision(x)
#define sz(x) (int)x.size()
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define endl '\n'

int main()
{
    

    int n;
    cin>>n;
    ll a[n+10];
    ffor(i,0,n) cin>>a[i];
    if(n==2)
    {
        cout<<max(a[0],a[1]);
        return 0;
    }

    ll dp[n+10][3];

    ffor(i,n,n+10) 
    {
        a[i]=-1e17;
        dp[i][0]=dp[i][1]=dp[i][2]=-1e17;
    }
    mem(dp,0);
    dp[n-1][0]=a[n-1];
    dp[n][1]=0;
    dp[n+1][2]=0;

    bfor(i,n,0)
    {
        dp[i][0]=a[i]+dp[i+2][0];
        dp[i][1]=max(dp[i+3][0]+a[i],dp[i+2][1]+a[i]);
        dp[i][2]=max({dp[i+3][1]+a[i],dp[i+4][0]+a[i],dp[i+2][2]+a[i]});
        
    }

   // ffor(i,0,n) cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    
    if(n&1)
    {
        cout<<max({dp[0][0],dp[0][1],dp[0][2],dp[1][0],dp[1][1],dp[2][0]});
    }
    else cout<<max({dp[0][0],dp[0][1],dp[1][0]});

    return 0;
}

