#include <bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll, ll>
#define pb push_back
#define rep0(i, n) for(ll i = 0;i<n;i++)
#define rep1(i, n) for(ll i = 1;i<n;i++)
#define all(v) v.begin(),v.end()
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int MOD = 1e9+7;
const int N = 1e5 + 5;
void solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    rep0(i, n){
        cin >> arr[i];
    }
    vector<ll> arr1 = arr;
    for(int i=n-2; i>=0; i--){
        arr1[i] += arr1[i+1];
        arr1[i] = arr1[i]%MOD;
    }
    ll ans = 0;
    for(int i=0; i<n-1; i++){
        ans += (arr[i]*arr1[i+1])%MOD;
        ans = ans%MOD;
    }
    cout << ans;
}

int main()
{
    fast;
    solve();
    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    return 0;
}
