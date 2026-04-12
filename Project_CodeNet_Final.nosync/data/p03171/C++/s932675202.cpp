#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 3100;
ll dp[maxn][maxn][2];
ll arr[maxn], n;

ll recursion(int l, int r, bool turn) {
    if(l > r) return dp[l][r][turn] = 0;
    if(dp[l][r][turn] != -1) return dp[l][r][turn];

    if(!turn) {
        // X's turn (First player)
        if(l == r) {
            return dp[l][r][turn] = arr[l];
        }
        else {
            return dp[l][r][turn] = max(recursion(l+1, r, !turn) + arr[l], recursion(l, r-1, !turn) + arr[r]);
        }
    }
    else {
        //Y's turn (Second Player)
        if(l == r) {
            return dp[l][r][turn] = -arr[l];
        }
        else {
            return dp[l][r][turn] = min(recursion(l+1, r, !turn) - arr[l], recursion(l, r-1, !turn) - arr[r]);
        }
    }
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<recursion(1, n, 0)<<"\n";
    return 0;
}
