/*
      @author: Charan Sai
*/
#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define ppi pair<int, int>
#define endl "\n"
#define nl cout << "\n"
#define deb(x) cout << #x << " " << x << endl;

const int MAX_N=3005;
int arr[MAX_N];
int n;
int dp[MAX_N][MAX_N][2]; 
// dp[i][j] = Max (X - Y) for subsequence arr[i...j] when 0th player starts the game
int bactrack(int start = 1, int end = n, int turn = 0) {
    // Base Case
    if(start == end) {
        if(turn == 0) return arr[start];
        return -arr[start];
    }
    if(dp[start][end][turn]!=-1) return dp[start][end][turn];
    // Choice
    int l = bactrack(start+1, end, !turn);
    int r = bactrack(start, end-1, !turn);
    if(turn == 0) {
        return 
        (dp[start][end][turn]=max(arr[start]+l,
                    arr[end]+r));
    }
    return 
    (dp[start][end][turn] = min(l-arr[start], r-arr[end]));
}


int32_t main() {
    IOS;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    cout << bactrack();
}