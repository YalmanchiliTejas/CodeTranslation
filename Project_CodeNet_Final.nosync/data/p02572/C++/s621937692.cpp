#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl                 "\n"
#define space                " "
#define TLE_na_ho            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX_SIZE             1024
#define MOD                  1000000007
#define pb                   push_back
#define fi                   first
#define se                   second
#define rep(i,a,n)           for(int i=a;i<n;i++)
#define repe(i,a,n)          for(int i=a;i<=n;i++)
#define repr(i,a,n)          for(int i=a;i>=n;i--)
#define ain(arr,n)           for(int i1=0;i1<n;i1++ ) cin>>arr[i1]
#define aout(arr,n)          for(int i1=0;i1<n;i1++ ) cout<<arr[i1]<<space



int main()
{
    TLE_na_ho;
    ll n;
    cin>>n;
    ll a[n];
    ll b[n+1]={0};
    rep(i,0,n){
    	cin>>a[i];
    	b[i+1]+=b[i]+a[i];
    }
    ll ans=0;
    rep(i,0,n)
    {
    	ll sum=(b[n]-b[i+1])%MOD;
    	ans+=a[i]*sum;
    	ans%=MOD;
    }

    cout<<ans;

}
