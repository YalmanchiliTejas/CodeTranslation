#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

int32_t main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
////////////////////////////////

    int n;
    
    cin >> n;
    int arr[n],pref[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
        if (i==0) pref[i] = arr[i];
        else pref[i] = (pref[i-1] + arr[i])%mod;
    }

    int ans = 0;
    for (int i=1;i<n;i++){
        ans += (arr[i] * pref[i-1])%mod;
    }

    cout<<ans%mod;


}
