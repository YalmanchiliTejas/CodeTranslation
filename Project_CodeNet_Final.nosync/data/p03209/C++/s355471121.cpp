
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    os << "{ ";
    REP(i, vec.size()) {
        os << vec[i] << " ";
    }
    os << "}";

    return os;
}

ll pow_mod(ll a, ll p) {
    ll res = 1;
    while(p) {
        if (p & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        p >>= 1;
    }

    return res;
}


ll mod_inv(ll a, ll m) {
    ll b = m, u = 0, v = 1;
    while(a) {
        ll t = b / a;
        swap(b -= t * a, a);
        swap(u -= t * v, v);
    }

    return (u % m + m) % m;
}

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}


#ifdef LOCAL
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N; ll X;
    cin >> N >> X;
    ++N;

    ll p[N+1];
    p[0] = 0;
    REP(i, N+1) {
        p[i+1] = p[i] * 2 + 1;
    }

    ll r = p[N] * 2 - 1;
    ll l = 0;

    ll ans = p[N];
    debug(N, ans)
    debug(l, r)
    cout << endl;

    while(1) {
        ll bn = r - l;
        ll mid = (bn + 2 - 1) / 2 + l;
        N = max(0, N-1);
        if (X > mid) {
            l = mid;
            --r;
        } else {
            ans -= p[N];

            if (X == mid) break;
            --ans;
            ++l;
            r = mid - 1;
        }
        debug(N, ans)
        debug(p[N])
        debug(l, r, bn)
        cout << endl;

        if (l >= r) break;
    }

    cout << fixed << setprecision(20);
    cout << ans << endl;

}
