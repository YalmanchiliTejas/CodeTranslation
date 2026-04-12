#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 1;
vector<int> g[N];
void solve(){
    int n, x, m;
    cin >> n >> x >> m;
    vector<int> dp;
    dp.push_back(x);
    if(n <= m){
        int sum = x;
        for(int i = 2; i <= n; i++){
            int val =(dp[(int)dp.size() - 1] * dp[(int)dp.size() - 1]) % m;
            sum += val;
            dp.push_back(val);
        }
        cout << sum << '\n';
        return;
    }
    vector<int> vis(m);
    int sum = x, idx1 = 0, idx2 = 0;
    vis[x] = 1;
    for(int i = 2; i <= n; i++){
        int val =(dp[(int)dp.size() - 1] * dp[(int)dp.size() - 1]) % m;
        if(!val){
            cout << sum << '\n';
            return;
        }
        if(vis[val]){
            idx1 = vis[val];
            idx2 = i - 1;
            break;
        }
        dp.push_back(val);
        vis[val] = i;
        sum += val;
    }
    int ans = 0;
    for(int i = 1; i < idx1; i++){
        ans += dp[i - 1];
    }
    n -= idx1 - 1;
    int len = idx2 - idx1 + 1;
    int curr = 0;
    for(int i = idx1; i <= idx1 + len; i++){
        curr += dp[i - 1];
    }
    for(int i = idx1; i < idx1 + (n % len); i++){
        ans += dp[i - 1];
    }
    cout << ans + curr * (n / len) << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        solve();
    }
}