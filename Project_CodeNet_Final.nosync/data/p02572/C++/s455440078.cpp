#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0; i < n ; i++) cin>>arr[i];
    long long sum[n+1];
    sum[0] = 0;
    for(int i=1;i <= n;i++)sum[i] = sum[i-1] + arr[i-1];
    const int mod = 1000000007;
    int64_t ans = 0;
    for(int i=1;i<=n;i++){
        ans += ((sum[i]%mod)*(arr[i]%mod))%mod;
        if(ans >= mod)ans %= mod;
    }
    cout<<ans<<"\n";
}