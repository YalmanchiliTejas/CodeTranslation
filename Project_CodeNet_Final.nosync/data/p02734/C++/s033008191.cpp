#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define endl '\n'
#define int long long int
#define TIME (chrono::steady_clock::now().time_since_epoch().count())
using namespace std;
const int lim = 3033;
const int mod = 998244353;
void solve(){

    int n,s;cin >> n >> s;
    vi in(n);
    FOR(i, n)cin >> in[i];


    vector<int> dp(lim), prev(lim);
    int ans = 0;
    FOR(i, n){
        fill(all(dp), 0);
        dp[in[i]] = i +1;
        for(int sum = in[i] + 1; sum <= s; sum++){
            dp[sum] = prev[sum - in[i]];
        }
        ans +=  dp[s] * (n - i);
        //debug(ans);
        ans %= mod;
        FOR(j, s+1){
            dp[j] += prev[j];
            dp[j] %= mod;
        }
        swap(dp, prev);
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t = 1;
    //    cin >> t;
    while(t--)solve();
}


