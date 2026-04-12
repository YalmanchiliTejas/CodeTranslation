#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(0);
#define debug(x) cout << x << endl;
#define sz(x) (int)x.size()
#define all(x) (x.begin(), x.end())
#define rall(x) (x.rbegin(), x.rend())
#define MAXN 10005
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define pb push_back
#define int long long
#define endl '\n'

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vii;
typedef vector <vi> matriz;

string k;
int d;
int dp[MAXN][105][2];

int calc(int pos, int res, bool ok){
    // cout << pos << " " << res << " " << ok << endl;
    if(dp[pos][res][ok] != -1) return dp[pos][res][ok];

    dp[pos][res][ok] = 0;

    if(pos == 0){
        for(int i = 1; i <= (ok ? (k[0] - '0') : (k[0] - '0' - 1)); i++){
            // cout << pos << " " << res << " " << ok << "ss" << endl;
            if((res + i) % d == 0){
                dp[pos][res][ok]++;
                dp[pos][res][ok] = dp[pos][res][ok] % MOD;
            }
        }
    } else {
        for(int i = 0; i <= 9; i++){
            bool st = (i < (k[pos] - '0') ? 1 : i > (k[pos] - '0') ? 0 : ok);
            if((res + i) % d == 0 && i != 0){
                // cout << pos << " " << res << " " << ok << endl;
                dp[pos][res][ok] = (dp[pos][res][ok] + calc(pos - 1, 0, st) + 1) % MOD;
            } else dp[pos][res][ok] = (dp[pos][res][ok] + calc(pos - 1, (res + i) % d, st)) % MOD;
        }
    }
    return dp[pos][res][ok];
}

int32_t main(){
    fastio
    cin >> k >> d;
    memset(dp, -1, sizeof(dp));
    cout << calc(sz(k) - 1, 0, 1) << endl;

    return 0;
}