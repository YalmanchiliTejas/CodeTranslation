#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n';

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;cin>>n;
    ll arr[n+1];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; ++i){
        cin>>arr[i+1];
        arr[i+1] += arr[i];
    }
    ll ans = 0, md = 1e9 + 7;
    for(int i = n; i>=1; --i){
        ans += (arr[i] - arr[i-1])*(arr[i-1]%md);
        ans %= md;
    }
    cout<<ans<<endl;
    return 0;

}