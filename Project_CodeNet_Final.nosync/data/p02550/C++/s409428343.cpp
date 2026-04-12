
//#pragma GCC target("avx2")
#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << "\n";
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    ll n, x, m;
    cin >> n >> x >> m;

    vi v(m);
    for(ll i = 0; i < m; i++) {
        v[i] = i * i % m;
    }

    vll ord;
    set<ll> idx;
    ll c = x;
    ll last;
    while(1) {
        if (idx.count(c) > 0) {
            last = c;
            break;
        }

        idx.insert(c);
        ord.pb(c);
        c = c * c % m;
    }

    ll ans = 0;

    int i = 0;
    for(; i < ord.size(); ++i) {
        if (ord[i] == last) {
            break;
        }
        ans += ord[i];
    }

    n -= i;

    ll len = ord.size() - i;
    ll p_sum = accumulate(ord.begin() + i, ord.end(), 0LL);

    ans += n / len * p_sum;

    FOR(j, i, i + n % len) {
        ans += ord[j];
    }

    print(ans);
}
