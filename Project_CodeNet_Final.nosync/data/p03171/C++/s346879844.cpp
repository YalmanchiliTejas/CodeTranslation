#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll dp[3000][3000];
bool dpv[3000][3000];
vector<int> deq(3000);

ll solve(int l, int r, int flag) { // flag = 1 -> Taro
    if(dpv[l][r])
        return dp[l][r];
    if(l > r)
        return 0;
    if(l == r) {
        dpv[l][r] = true;
        if(flag)            
            return dp[l][r] = deq[l];
        else
            return dp[l][r] = -deq[l];
    }
  	dpv[l][r] = true;
    if(flag) {
        return dp[l][r] = max((ll)deq[l] + solve(l+1, r, 1-flag), (ll)deq[r] + solve(l, r-1, 1-flag));
    } else {
        return dp[l][r] = min(solve(l+1, r, 1-flag) - (ll)deq[l], solve(l, r-1, 1-flag) - (ll)deq[r]);
    }
}

int main() {
    int n, tp;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> deq[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dpv[i][j] = false;
        }
    }
    cout << solve(0, n-1, 1) << "\n";
}