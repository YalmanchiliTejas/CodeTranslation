#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007ll
#define mod1 998244353ll
#define endl '\n'
#define inf ((ll)1e18+1)
#include<chrono>
using namespace chrono;
mt19937_64 rng(high_resolution_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define debr(x,y) {cout<<"-->  "<<#x<<" to "<<#y<<" :  "; auto itr=x; while(itr!=y) cout<<(*itr++)<<' '; cout<<endl; }
#define deba(x) {cout<<"-->  "<<#x<<" :  "; for(auto ele:(x)) cout<<ele<<"  "; cout<<endl; }
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout<<endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a <<"  ,  ";
    err(++it, args...);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll ar[n];
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    ll sum=0;
    for(int x=0;x<n;x++){
        cin>>ar[x];
        sum+=ar[x];
        dp[x][x]=ar[x];
    }
    for(ll len=2;len<=n;len++){
        for(ll x=0;x<n;x++){
            ll y=x+len-1;
            if(y>=n)break;
            ll sum1=0,sum2=0,sum3=0;
            if(x+2<=y)sum1=dp[x+2][y];
            if(x+1<=y-1)sum2=dp[x+1][y-1];
            if(x<=y-2)sum3=dp[x][y-2];
            ll ans1=ar[x]+min(sum1,sum2);
            ll ans2=ar[y]+min(sum2,sum3);
            dp[x][y]=max(ans1,ans2);
        }
    }
    ll X=dp[0][n-1];
    ll Y=sum-X;
    cout<<X-Y<<endl;
    return 0;
}