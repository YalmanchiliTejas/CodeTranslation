#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const ll MOD = (ll)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll mp(ll a,ll b){ll ret=1;while(b){if(b&1)ret=ret*a%MOD;a=a*a%MOD;b>>=1;}return ret;}

ll vec[200003];
ll osum[200003];
ll esum[200003];

ll oro[200003];
ll ero[200003];

ll dp[200003][3];

int n;
ll go(int o, int pp) {
    if (o > n) return -(ll)1e17;
    if (o == n) {
        if (pp == 2) return vec[o];
        else return -(ll)1e17;
    }
    if (dp[o][pp] > -(ll)1e18) return dp[o][pp];

    ll ret = -(ll)1e17;
    if (pp < 2) ret = max(ret, go(o + 3, pp + 1));
    ret = max(ret, go(o + 2, pp));

    return dp[o][pp] = ret + vec[o];
}

int main() {
    memset(dp, -0x3f, sizeof(dp));
    scanf("%d", &n);

    for (int i = 1; i <= n + 2; i++) {
        if (i < n + 1) scanf("%lld", &vec[i]);

        osum[i] = osum[i - 1];
        esum[i] = esum[i - 1];
        oro[i] = oro[i - 1];
        ero[i] = ero[i - 1];

        if (i < n + 1) {
            if (i % 2) osum[i] += vec[i], oro[i]++;
            else esum[i] += vec[i], ero[i]++;
        }
    }

    ll ans = -1e18;
    for (int i = 1; i <= n; i++) {
        if (oro[i - 1] + oro[n] - oro[i] == n / 2)
            ans = max(ans, osum[i - 1] + osum[n] - osum[i]);

        if (oro[i - 1] + ero[n] - ero[i] == n / 2)
            ans = max(ans, osum[i - 1] + esum[n] - esum[i]);

        if (ero[i - 1] + oro[n] - oro[i] == n / 2)
            ans = max(ans, esum[i - 1] + osum[n] - osum[i]);

        if (ero[i - 1] + ero[n] - ero[i] == n / 2)
            ans = max(ans, esum[i - 1] + esum[n] - esum[i]);


        ////
        if (oro[i - 1] + oro[n] - oro[i + 1] == n / 2)
            ans = max(ans, osum[i - 1] + osum[n] - osum[i + 1]);

        if (oro[i - 1] + ero[n] - ero[i + 1] == n / 2)
            ans = max(ans, osum[i - 1] + esum[n] - esum[i + 1]);

        if (ero[i - 1] + oro[n] - oro[i + 1] == n / 2)
            ans = max(ans, esum[i - 1] + osum[n] - osum[i + 1]);

        if (ero[i - 1] + ero[n] - ero[i + 1] == n / 2)
            ans = max(ans, esum[i - 1] + esum[n] - esum[i + 1]);
    }

    printf("%lld", max(ans, go(1, 0)));
}