#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i = 0; i < int(n); i++)

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
const int MOD = 1000000007;

int D;
string K;
ll DP[10001][2][100];
int l;

ll fun(int pos, int f, int sum) {
    if(pos == l) {
        return sum % D == 0;
    }

    if(DP[pos][f][sum] != -1) return DP[pos][f][sum];

    int LMT = 9;
    if(f == 0) LMT = K[pos] - '0';
    ll ans = 0;

    for(int i = 0; i <= LMT; i++) {
        int tempf = f;
        if(i < LMT) tempf = 1;
        ans = (ans + fun(pos + 1, tempf, (sum + i) % D)) % MOD;
    }
    return DP[pos][f][sum] = ans;
}

int main() {
    IOS;
    memset(DP, -1, sizeof(DP));
    cin >> K >> D;
    l = K.length();
    ll ans = fun(0, 0, 0) - 1;
    if (ans < 0) ans = MOD - 1;
    cout << ans;
    return 0;
}