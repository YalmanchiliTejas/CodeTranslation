#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MIN = -1000000000000000000;

ll getMax(vector<ll>& arr, vector<vector<ll>>& dp, ll here, ll left){
    if(dp[here][left] != MIN){
        return dp[here][left];
    }
    if(left == 0){
        return dp[here][left] = getMax(arr, dp, here+2, left) + arr[here];
    }
    ll inc = arr[here] + getMax(arr, dp, here+2, left);
    ll exc = getMax(arr, dp, here+1, left-1);
    return dp[here][left] = max(inc, exc);
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> arr(N);
    for(int i = 0 ; i < N; ++i){
        cin >> arr[i];
    }
    vector<vector<ll>> dp(N+2, vector<ll>(3, MIN));
    for(int i = 0 ; i < 2; ++i){
        dp[N][i] = 0;
        dp[N+1][i] = 0;
    }
    dp[N][2] = MIN-1;
    dp[N+1][2] = MIN-1;

    ll left = 1 + (N%2 == 1);
    ll ret = getMax(arr, dp, 0, left);

    cout << ret << endl;

}