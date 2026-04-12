#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    i64 n,a[200001],sum{},ans{};
    i64 MOD = 1000000007;
    cin>>n;
    for(i64 i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    for(i64 i=0;i<n-1;i++){
        sum -= a[i];
        ans += ((sum%MOD)*a[i])%MOD;
        ans = ans%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
