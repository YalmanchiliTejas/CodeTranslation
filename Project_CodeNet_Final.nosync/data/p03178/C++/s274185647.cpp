#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-7
#define f first
#define s second
using namespace std;
const ll MOD = 1e9+7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
ll fast_power(ll x, ll p){
    ll res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * x);
        }
        p = p >> 1;
        x = (x*x);
    }
    return res;
}

string k;
int d;
ll dp[10005][105][2][2];

ll solve(int index, int sum, int close, int used) {
    if (index == k.length()) {
        if (!sum && used)
            return 1;
        else
            return 0;
    }
    if (dp[index][sum][close][used] != -1)
        return dp[index][sum][close][used];
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        if (close && ((i + '0') > k[index])) break;
        int zeroes = i?1:used;
        if (close && (i + '0') == k[index]) ans = (ans + solve(index + 1, (sum + i)%d, close, zeroes))%MOD;
        else ans = (ans + solve(index + 1, (sum + i)%d, 0, zeroes))%MOD;
    }
    return dp[index][sum][close][used] = ans;
}

int main() {
    IO;
    cin >> k;
    cin >> d;
    for (int i = 0; i < k.length(); i++) {
        for (int j = 0; j < d ;j++) {
            dp[i][j][0][0] = -1, dp[i][j][1][1] = -1, dp[i][j][0][1] = -1, dp[i][j][1][0] = -1;
        }
    }
    cout << solve(0,0,1,0) << "\n";
    return 0;
}
