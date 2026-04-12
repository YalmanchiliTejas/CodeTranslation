#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define getMat(x, n, m, val) vector<vector<ll>> x(n, vector<ll> (m, val))
#define setp fixed<<setprecision
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll M=1000000000+7;
 
ll power(ll x,ll n)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

int main(){
    fastio;
    ll n;
    cin>>n;
    ll a[n];
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        sum-=a[i];
        ans = (ans%M + ((a[i]%M)*(sum%M))%M)%M;
    }
    cout<<ans<<endl;
    return 0;
}