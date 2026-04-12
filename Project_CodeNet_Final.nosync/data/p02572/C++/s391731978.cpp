#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define ld long double
#define iii tuple<int, int, int>
#define sc scanf
#define pb push_back
#define FOR(x, n) for(int i=x; i<=n; ++i)
#define MOD 1000000007

ll a[200005];

int main() {

    int n;
    sc("%d", &n);

    a[0] = 0;

    FOR(1, n) {
        sc("%lld", &a[i]);
        a[i] += a[i-1];
    }

    ll ans = 0;

    FOR(1, n) {

        ans += (((a[n] - a[i])%MOD) * (a[i] - a[i-1]) );

        ans %= MOD;
    }

    printf("%lld\n", ans);
}

