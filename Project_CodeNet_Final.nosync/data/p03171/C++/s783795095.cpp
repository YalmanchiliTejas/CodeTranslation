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
// dp[i][j][0] = Max (X - Y) for subsequence arr[i...j] when it is 0th player turn. Whatever he chooses add it in X
// dp[i][j][1] = Max (X - Y) for subsequence arr[i...j] when it is 1st player turn. Whatever he chooses add it in Y
int Top_Down(int start = 1, int end = n, int turn = 0) {
    // Base Case
    if(start == end) {
        if(turn == 0) return arr[start];
        return -arr[start];
    }
    if(dp[start][end][turn]!=-1) return dp[start][end][turn];
    // Choice
    int l = Top_Down(start+1, end, !turn);
    int r = Top_Down(start, end-1, !turn);
    if(turn == 0) {
        return 
        (dp[start][end][turn]=max(arr[start]+l,
                    arr[end]+r));
    }
    return 
    (dp[start][end][turn] = min(l-arr[start], r-arr[end]));
}

/*
dp[i][j][1] = Max (X - Y) for subsequence arr[i...j] when it is 1st player turn. Whatever he chooses add it in Y
This is unnecessary. So try to do it without storing 'turn'.
X1 - (Y1 - (X2 - Y2)) = (X1 + X2) - (Y1 + Y2)
Since the - sign alternates so we no need turn.
*/
int dp2[MAX_N][MAX_N];
//dp[i][j] = Max(X-Y) for subsequence arr[i..j]
//when it is 0th player turn to choose
int Top_Down2(int start = 1, int end = n) {
    // Base Case
    if(start == end) {
        return arr[start];
    }
    if(dp2[start][end] != -1) return dp2[start][end];
    // Choice
    return (dp2[start][end]=
        max(arr[start]-Top_Down2(start+1,end),arr[end]-Top_Down2(start,end-1))
    );
}

int32_t main() {
    IOS;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    cout << Top_Down2();
}