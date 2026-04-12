/* lib.cpp */

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>

#define DEBUG(x) cout << #x << " = " << (x) << ",";

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using graph = vector<vector<int>>;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int edx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int edy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template <class T> void chmin(T &a, T b) { a = min(a, b); }
template <class T> void chmax(T &a, T b) { a = max(a, b); }

ll modpow(ll a, ll b, ll p = MOD) {
    ll ret = 1;
    while (b != 0) {
        if ((b & 1) == 1) ret *= a;
        a *= a;
        if (a >= p) a %= p;
        if (ret >= p) ret %= p;
        b >>= 1;
    }
    return ret;
}

int digit(ll x, ll base = 10) { int ret = 0; while (x) { x /= base; ret++; } return ret; }

int sumOfDigit(ll x, ll base = 10) {
    int ret = 0;
    while(x) {
        ret += x % base;
        x /= base;
    }
    return ret;
}

ll factrial(int n) { ll ret = 1; for(int i = 1;i <= n;i++) { ret *= i; } return ret; }

ll gcd(ll a, ll b) { while(b != 0) { a %= b; swap(a, b); } return a; }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll modinv(ll a, ll p = MOD) {
    ll b = p, u = 1, v = 0;
    while(b) {
        ll tmp = a / b;
        a -= tmp * b; u -= tmp * v;
        swap(a, b); swap(u, v);
    }
    u %= p;
    if (u < 0) u += p;
    return u;
}

bool isprime(ll p) {
    if(p <= 1) return false;
    ll s = min(p - 1, (ll)ceil(sqrt(p)));
    for(int i = 2;i <= s;i++)
        if(p % i == 0) return false;
    return true;
}

ll minDivisor(ll x, ll n = 2) {
    if(x <= 1) return 1;
    ll s = min(x - 1, (ll)ceil(sqrt(x)));
    for(int i = n;i <= s;i++)
        if(x % i == 0) return i;
    return x;
}

ll countDivisor(ll x) {
    map<ll, int> m;
    if(x <= 1) return 1;
    ll s = min(x - 1, (ll)ceil(sqrt(x)));
    for(int i = 2;i <= s;i++) {
        if(x % i == 0) {
            x /= i;
            m[i]++;
            i = 1;
        }
    }
    if(x != 1) m[x]++;
    ll ret = 1;
    for(auto i : m) {
        ret *= i.second + 1;
    }
    return ret;
}

class disjoint_set
{
    vector<int> _parent, _size;

public:
    disjoint_set(int n) : _parent(n), _size(n) {
        for (int i = 0; i < n; i++) {
            _parent[i] = i;
            _size[i] = 1;
        }
    }
    int root(int x) {
        if (_parent[x] == x) return x;
        return _parent[x] = root(_parent[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        _parent[rx] = ry;
        _size[ry] += _size[rx];
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return _size[root(x)]; }
};

void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
}

void solve() {
    string s;
    cin >> s;
    if(s == "AAA" || s == "BBB") cout << "No" << endl;
    else cout << "Yes" << endl;
}

int main() {
    init();
    solve();
    return 0;
}
