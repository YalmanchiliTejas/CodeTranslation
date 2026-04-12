    #include <iostream>
    
    using namespace std;
    typedef long long int ll;
    
    ll p =1e9+7;
    int main() {
        int n;cin>>n;
        ll a[n] ;for (int i=0;i<n;++i)cin>>a[i];
        ll pref[n];pref[0]=a[0];
        
        for (int i=1;i<n;++i)pref[i]=(a[i]+pref[i-1])%p;
        
        ll ans = 0 ,sum = pref[n-1];
        for (int i=0;i<n-1;++i){
            ans = (ans + a[i] * (sum - pref[i]+p))%p;
        }
        cout<<ans;
        
    }