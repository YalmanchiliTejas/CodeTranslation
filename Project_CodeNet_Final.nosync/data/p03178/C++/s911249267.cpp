#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx4 10005
#define mx5 100005
#define mx52 200005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll dp[mx4][101] = {};

ll compute(string k, int d) {
    ll ans = 0;
    int tag = 0;
    int l = k.length();
    for (int i = 0; i < l; i++) {
        for (int digit = 0; digit < k[i]-'0'; digit++)
            ans = (ans + dp[l-i-1][(d - (digit + tag) % d) % d]) % mod;
        tag = (tag + (k[i] - '0') % d) % d;
    }
    if (tag != 0) {
        ans = (ans + mod - 1) % mod;
    }
    return ans;
}

int main() {
    nfs
    int i, d, l;
    string k;
    cin >> k >> d;
    l = k.length();
    dp[0][0] = 1;
    
    for (int i = 1; i <= l; i++)
        for (int r = 0; r < d; r++)
            for (int digit = 0; digit < 10; digit++)
                dp[i][r] = (dp[i][r] + dp[i-1][(r + (d - digit%d)%d)%d]) % mod;
    
    cout << compute(k, d);
}