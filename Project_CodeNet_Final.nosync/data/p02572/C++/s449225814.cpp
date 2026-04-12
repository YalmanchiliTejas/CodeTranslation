#include <bits/stdc++.h>
using namespace std;

#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define int long long int
#define ll long long
#define ld long double

int mod=1e9+7;

bool isPrime(ll n){if(n<2)return false;for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}

ll lcm(ll x,ll y){
    return (x*y)/(__gcd(x,y));
}


signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
        string s;
        int n;
        cin>>n;
        vector<int> a(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            sum%=mod;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            sum-=a[i];
            if (sum < 0)sum += mod;
            ans+=sum*a[i];
            ans%=mod;
        }
        cout<<ans%mod;
        
    }
    return 0;
}