#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
#define pb push_back
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

int N, a[3030], dp[2][3030][3030];

int dfs(int p, int l, int r)
{
    if(~dp[p][l][r]){
        return dp[p][l][r];
    }
    if(l == r){
        int res;
        if(p % 2 == 0){
            res = a[l];
        }
        else {
            res = -a[l];
        }
        return dp[p][l][r] = res;
    }
    int res;
    if(p % 2 == 0){
        res = dfs(1, l + 1, r) + a[l];
        res = max(res, dfs(1, l, r - 1) + a[r]);
    }
    else {
        res = dfs(0, l + 1, r) - a[l];
        res = min(res, dfs(0, l, r - 1) - a[r]);
    }
    return dp[p][l][r] = res;
}

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0, N - 1) << endl;

    return 0;
}
/*



*/

