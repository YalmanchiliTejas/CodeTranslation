#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define ld long double
#define pb push_back 
#define ff first 
#define ss second
#define all(c) c.begin(), c.end()
#define sz(z) (int)z.size()
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rev(i,a,b) for(int i=a; i>=b; i--)
//Debugging tools 
#define debug(v) cout<<#v<<endl;for(ll i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
#define debugn(v,n) cout<<#v<<endl;for(ll i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;
#define deb(sum) cout<<#sum<<" = "<<sum<<endl;
//Predefined values
#define INF (ll)1e18
#define endl "\n"
#define pi 3.142857142857143

const ll MOD = 1e9 + 7;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t=1;    
    //cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        rep(i,0,n) cin>>a[i];
        vector<ll> pref(n);
        rep(i,0,n){
            if(i==0)
                pref[i] = a[i];
            else{
                pref[i] = pref[i-1] + a[i];
            }
        }
        ll ans = 0;
        rep(i,0,n-1){
            ans += ((a[i]%MOD)*((pref[n-1]-pref[i])%MOD))%MOD;
            ans %= MOD;
        }   
        cout<<ans%MOD<<endl;

    }
  return 0;
 }















