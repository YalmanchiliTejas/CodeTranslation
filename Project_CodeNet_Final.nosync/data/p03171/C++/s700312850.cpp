#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define sa(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define scan() int n; cin>>n ; int a[n]; for(int i = 0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
using namespace std;
template <typename T, typename U>
T max(T x, U y)
{
    return x>y ? x : y;
}
template <typename T, typename U>
T min(T x, U y)
{
    return x<y ? x : y;
}
ll b[1000000];
ll _(ll i,ll j)
{
    if(i==0)return b[j];
    else return b[j]-b[i-1];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;cin >> n;
    ll a[n];ll sm=0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];sm+=a[i];
    }
    
    b[0]=a[0];
    for (int i = 1; i < n; ++i)
    {
        b[i]=a[i]+b[i-1];
    }
    ll dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(ll i=n-1;i>=0;i--)
    {
        for(ll j=i;j<n;j++)
        {
            if(i==j)dp[i][j]=a[i];
            else
            {
                ll p1=dp[i+1][j];ll q1=dp[i][j-1];
                ll p2=_(i+1,j)-p1;ll q2=_(i,j-1)-q1;
                dp[i][j]=max(p2+a[i],q2+a[j]);
                /*if(p>q)dp[i][j]=a[j];
                else if(p<q)dp[i][j]=a[i];
                else if(p==q)dp[i][j]=max(a[i],a[j]);*/
            }
        }
    }
    /*for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << dp[0][n-1]-(sm-dp[0][n-1]);
    //trace(sm);
    }