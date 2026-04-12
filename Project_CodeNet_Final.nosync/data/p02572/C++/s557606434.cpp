#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) (v).begin() , (v).end()
#define sumof(v) accumulate(all(v), 0LL, plus<ll>())
#define maxof(v) max_element(all(v))
#define minof(v) min_element(all(v))
#define inf INT_MAX

int main(){
    FASTIO
    int testCases = 1;
    // cin>>testCases;
    while(testCases--){
        ll N; cin>>N;
        vector<ll> a(N);
        for(int i=0; i<N; ++i) cin>>a[i];
        vector<ll> prefixPro(N), suffixPro(N);
        prefixPro[0] = a[0]%MOD;
        suffixPro[N-1] = a[N-1]%MOD;
        for(int i=1; i<N; ++i) prefixPro[i] = (a[i]+prefixPro[i-1])%MOD;
        for(int i=N-2; i>=0; i--) suffixPro[i] = (a[i]+suffixPro[i+1])%MOD;
        ll ans = 0;
        for(int i=0; i<N; ++i){
            ll left = 0;
            if(i-1>=0) left = prefixPro[i-1];
            // cout<<"Left = "<<left<<endl;
            // cout<<a[i]<<endl;
            // if(i+1<N) right = suffixPro[i+1];
            ans = ans + (a[i]*left)%MOD;
            ans = ans%MOD;
        }
        cout<<ans<<endl;
    }
}