/**
 * Created by: WeirdBugsButOkay
 * 20-07-2020, 12:41:20
**/

#include <bits/stdc++.h>

#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define sz(x) (ll)x.size()
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
template <class T> using v = vector <T>;
typedef v <int> vi;
typedef v <ll> vl;
typedef v <pii> vii;
typedef v <pll> vll;
typedef v <vi> vvi;
typedef v <vl> vvl;
typedef v <bool> vb;
template <class T> ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << "{";
    string sep;
    for (const auto &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
template <class T, class U> ostream& operator<<(ostream &os, const set<T, U> &v) { 
    os << "{";
    string sep;
    for (const auto &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
template <class A, class B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
#ifndef WB_DEBUG
#define nl() cout << endl;
#endif
#ifndef WBOK_DEBUG
#define deb(...) cout << #__VA_ARGS__ << " = " << __VA_ARGS__ << "\n";
#endif

template <class T> void osort(v <T> &a, v <T> &b) {
    a.resize(sz(b));
    iota(all(a), 0);
    sort(all(a), [&](int i, int j) { return b[i] < b[j] || (b[i] == b[j] && i < j);});
}

template <class A, class B> ll lcm(A a, B b) {
    return (((ll)a / __gcd((ll)a, (ll)b)) * (ll)b);
}

ll inf;
vl f, iv, primes, spf;
vvl pf;
vb isp;
vii dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

ll exp(ll a, ll b, ll inf) {
    ll res = 1;
    while(b > 0) {
        if(b & 1)
            res = (res * a) % inf;
        a = (a * a) % inf;
        b >>= 1;
    }
    return res;
}

ll inv(ll n) {
    return exp(n, inf - 2, inf);
}

void facts(ll N) {
    f.resize(N + 1);
    iv.resize(N + 1);
    f[0] = iv[0] = 1;
    for(ll i = 1; i <= N; i++) {
        f[i] = (f[i - 1] * i) % inf;
        iv[i] = exp(f[i], inf - 2, inf);
    }
}

ll ncr(ll n, ll r) {
    return (((f[n] * iv[r]) % inf) * iv[n - r]) % inf;
}

void seive(ll N) {
    isp.assign(N + 1, 1);
    spf.resize(N + 1);
    isp[0] = isp[1] = 0;
    spf[0] = 2, spf[1] = 0;
    for(ll i = 2; i <= N; i++) {
        if(isp[i]) {
            primes.pb(i);
            spf[i] = i;
        }
        for(ll j = 0; j < sz(primes) && i * primes[j] <= N && primes[j] <= spf[i]; j++) {
            isp[i * primes[j]] = 0;
            spf[i * primes[j]] = primes[j];
        }
    }
}

void findpf(ll N) {
    pf.resize(N + 1);
    for(ll i = 2; i <= N; i++) {
        for(ll j : primes) {
            if(j > N)
                break;
            if(i % j == 0) {
                pf[i].pb(j);
            }
        }
    }
}

void init();
void solve();

int main() {
    init();
    int q = 1;
    //scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

/**
 * Code begins here
 * Stuff to check: overflow, constraints & bounds, special cases 
**/

void init() {
    inf = (ll)1e9 + 7;
    return;
}

void solve() {
    int x;
    cin >> x;
    if(x >= 30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return;
}
