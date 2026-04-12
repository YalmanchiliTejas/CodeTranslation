# include <bits/stdc++.h>
using namespace std;
# define lli long long int
# define MOD 1000000007
# define INF 10000000000009
# define MAX 1000000


lli arr[3001];
lli dp[3001][3001][2];

lli findRes(lli i, lli j, lli ch){
    if(i > j)
        return 0;

    if(dp[i][j][ch] != -1)
        return dp[i][j][ch];

    if(ch == 0)
        return dp[i][j][ch] = max(arr[i] + findRes(i + 1, j, 1), arr[j] +
            findRes(i, j - 1, 1));
    return dp[i][j][ch] = min(findRes(i + 1, j, 0), findRes(i, j - 1, 0));

}

void solve(){
    lli n;
    cin >> n;

    lli sum = 0;
    for(lli i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << 2*findRes(0, n - 1, 0) - sum;

}

int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
