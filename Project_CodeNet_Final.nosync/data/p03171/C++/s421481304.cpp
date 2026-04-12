#include <bits/stdc++.h>

using namespace std;

long long dp[3001][3001], arr[3001], n;
bool vis[3001][3001];

long long helper(int left, int right, int turn){

    if(left > right)
        return 0;

    if(vis[left][right])
        return dp[left][right];

    if(turn == 0){
        dp[left][right] = max(helper(left + 1, right, 1) + arr[left], helper(left, right - 1, 1) + arr[right]);
    } else  {
        dp[left][right] = min(helper(left + 1, right, 0) - arr[left], helper(left, right - 1, 0) - arr[right]);
    }

    vis[left][right] = true;

    return dp[left][right];

}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << helper(0, n - 1, 0) << "\n";

    return 0;
}