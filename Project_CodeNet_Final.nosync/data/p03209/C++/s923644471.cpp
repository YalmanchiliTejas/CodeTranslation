#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;


int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> p(N+1);
    vector<ll> b(N+1);
    p[0] = 1;
    b[0] = 1;
    REP(i, N) {
        b[i+1] = 2 * b[i] + 3;
        p[i+1] = 2 * p[i] + 1;
    }
    ll ans = 0;
    ll L = N;
    while(L >= 0) {
        if (X == 1) {
            if (L == 0) ans++;
            break;
        }
        if (X == b[L]) {
            ans += p[L];
            break;
        }
        ll mid = b[L]/2 + 1;
        L--;
        if (L < 0) {
            ans++;
            break;
        }
        if (mid < X) {
            ans += p[L] + 1;
            X = X - mid;
        } else if (mid > X) {
            X = X - 1;
        } else {
            ans += p[L] + 1;
            break;
        }
    }
    PRINT(ans);
    return 0;
}
