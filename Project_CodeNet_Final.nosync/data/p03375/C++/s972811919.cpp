#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define pr pair<int, int>
#define x first
#define y second
using namespace std;

template<typename T>
void read(T& n){
    char ch; int sign = 1;
    while (!isdigit(ch = getchar())) if (ch == '-') sign = -1;
    n = ch - '0';
    while (isdigit(ch = getchar())) n = n * 10 + ch - '0';
    n *= sign;
}
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const int N = 3111;
int n, m;
ll c[N][N], s[N][N], po[N], po2[N];

void upd(ll& x, ll y){x += y; if (x >= m) x -= m;}
ll mut(ll a, ll b){
    ll y = 1, t = a;
    for (; b; b >>= 1, t = t * t % m)
        if (b & 1) y = y * t % m;
    return y;
}

int main(){
    read(n), read(m);
    po[0] = po2[0] = 1;
    rep(i, 1, n) po[i] = po[i-1] * 2 % m;
    rep(i, 1, n) po2[i] = po2[i-1] * 2 % (m - 1);
    c[0][0] = s[0][0] = 1;
    rep(i, 1, n) rep(j, 0, n)
        c[i][j] = (c[i-1][j] + (j ? c[i-1][j-1] : 0)) % m;
    rep(i, 1, n) rep(j, 0, n)
        s[i][j] = (s[i-1][j] * j + (j ? s[i-1][j-1] : 0)) % m;
    ll ans = 0;
    rep(i, 0, n){
        ll res = 0;
        rep(j, 0, i){
            ll t = (s[i][j] + s[i][j+1] * (j + 1)) % m;
            t = t * mut(po[n-i], j) % m * mut(2, po2[n-i]) % m;
            upd(res, t);
        }
        (res *= c[n][i]) %= m;
        if (i % 2 == 0) upd(ans, res);
        else ans = (ans - res + m) % m;
    }
    cout << ans << endl;
    return 0;
}