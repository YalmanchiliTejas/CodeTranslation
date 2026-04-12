#include <bits/stdc++.h>
using namespace std;
#define int long long int
int dp[3001][3001];

int solve(vector<int>& a, int st, int end, int chance, int diff) {
    if(st > end) return 0;
    if(dp[st][end] != -1) return dp[st][end];
    else if(chance & 1) {
        int opt1 = -a[st] + solve(a, st+1, end, chance+1, diff - a[st]);
        int opt2 = -a[end] + solve(a, st, end-1, chance+1, diff - a[end]);
        return dp[st][end] = min(opt1, opt2);
    }
    else {
        int opt1 = a[st] + solve(a, st+1, end, chance+1, diff + a[st]);
        int opt2 = a[end] + solve(a, st, end-1, chance+1, diff + a[end]);
        return dp[st][end] = max(opt1, opt2);
    }
}

int32_t main() {
    int N; cin>>N;
    vector<int> a(N+1);
    for(int i=0; i<N; i++) cin>>a[i];
    memset(dp, -1, sizeof dp);
    int X, Y;
    X = Y = 0;
    cout<<solve(a, 0, N-1, 0, 0)<<endl;
    return 0;
}
