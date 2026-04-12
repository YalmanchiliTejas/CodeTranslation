#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define fcin ios::sync_with_stdio(false); cin.tie(nullptr);
#define inf 0x3f3f3f3f
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> pii;

/* 
 * * stuff you should look for
 * * int overflow, array bounds
 * * special cases (n=1?), set tle
 * */

string s;
int n, k;
ll dp[100][4][2];

ll solve(int i, int nonz, int block){
    if(i == n and nonz == k) return 1;
    if(i == n or nonz > k) return 0;

    ll& ret = dp[i][nonz][block];
    if(~ret) return ret;

    ret = 0;

    ret += solve(i + 1, nonz, block and s[i] == '0');
    for(int j = 1; j <= (block ? s[i] - '0' : 9); j++){
        ret += solve(i + 1, nonz+1, (block and j >= (s[i] - '0')));
    }

    return ret;
}

int main(){
    fcin;

    cin >> s;

    n = s.size();

    cin >> k;

    memset(dp, -1, sizeof dp);
    ll ans = solve(0, 0, 1);

    cout << ans << endl;
    return 0;
}

