#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// #define endl "\n"
#define TARO true
#define LIRO false

ll recurse(bool who, ll i, ll j, vector<ll>& arr, vector<vector<vector<ll>>>& dp) {
    if (i == j) {
        return (who ? arr[i]: -arr[i]);
    }

    if (dp[who][i][j] != LLONG_MIN) {
        return dp[who][i][j];
    }

    if (who) {
        ll one = arr[i] + recurse(!who, i+1, j, arr, dp);
        ll two = arr[j] + recurse(!who, i, j-1, arr, dp);

        return dp[who][i][j] = max(one, two);
    } else {
        ll one = - arr[i] + recurse(!who, i + 1, j, arr, dp);
        ll two = - arr[j] + recurse(!who, i, j - 1, arr, dp);
        return dp[who][i][j] = min(one, two);
    }
}

int main(void) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> arr (n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<vector<ll>>> dp (2, vector<vector<ll>> (n+1, vector<ll> (n+1, LLONG_MIN)));
    cout << recurse(TARO, 0, n-1, arr, dp) << endl;



    
    return 0;
}