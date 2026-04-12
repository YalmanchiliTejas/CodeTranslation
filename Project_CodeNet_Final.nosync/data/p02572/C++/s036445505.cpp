#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    ll n;
    cin>>n;
    vector<ll> a (n),pref(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    pref[0]=a[0];
    for(ll i=1;i<n;i++)
        pref[i]=(pref[i-1]+a[i])%mod;
    ll ans=0;
    for(ll i=1;i<n;i++)
        ans=(ans+(pref[i-1]*a[i])%mod)%mod;
    cout<<ans;

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}