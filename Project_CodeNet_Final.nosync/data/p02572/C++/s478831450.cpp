#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    
    vector<ll> a(n);
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum += a[i];
        sum %= mod;
    }

    ll ans = 0;
    for(int i=1; i<=n; i++){
        sum -= a[i-1];
        if(sum < 0){
            sum += mod;
        }
        ans += a[i-1]*sum%mod;
      
    }
    cout<<ans%mod<<endl;
    return 0;
}
