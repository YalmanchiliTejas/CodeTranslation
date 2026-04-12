#include<bits/stdc++.h>
using namespace std;
     
#define ll long long
#define loop(i,a,n) for(ll i=a;i<n;++i)
#define revloop(i,a,b) for(ll i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF 9999999999999999
#define MOD 1000000007

void func()
{
    ll n;
    cin>>n;
    ll a[n],sum=0;
    loop(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    ll ans=0;
    loop(i,0,n){
        sum=sum-a[i];
        ans=(ans % MOD + (a[i]*(sum % MOD)) % MOD) % MOD;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif
 
    ll t=1;
    //cin>>t;
    //solve();
    while(t--)
    {
        func();
    }

}
