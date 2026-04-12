#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;


ll power(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}

struct seg {
    int l, r;
    ll res0, res1, res2;

};

bool operator<(const seg& s1, const seg& s2) {
    return s1.l < s2.l;
}

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<pii> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = make_pair(h[i], i);
    }
    sort(p.rbegin(), p.rend());
    vector<seg> a;
    vector<int> act(n, 0);

    ll lh = p[0].first;
    for (int i = 0; i < n; ++i) {
        ll ch = p[i].first;
        for (int j = 0; j < a.size(); ++j) {
            a[j].res0 = (a[j].res0 * power(2, lh - ch)) % mod;
            a[j].res1 = (a[j].res1 * power(2, lh - ch)) % mod;
        }
        int id = p[i].second;
        seg s;
        s.l = s.r = id;
        s.res0 = s.res1 = 1;
        s.res2 = 0;
        act[id] = 1;
        a.push_back(s);
        sort(a.begin(), a.end());
        lh = ch;
        bool ok = 1;
        while (ok) {
            ok = 0;
            for (int j = 0; j + 1 < a.size(); ++j) {
                if (a[j].r + 1 == a[j + 1].l) {
                    ll res0 = 0, res1 = 0, res2 = 0;
                    if (((a[j].r - a[j].l) % 2) == 0) {
                        res0 = (res0 + (a[j].res0 * a[j + 1].res1) % mod) % mod;
                        res1 = (res1 + (a[j].res1 * a[j + 1].res0) % mod) % mod;
                    }
                    else {
                        res0 = (res0 + (a[j].res0 * a[j + 1].res0) % mod) % mod;
                        res1 = (res1 + (a[j].res1 * a[j + 1].res1) % mod) % mod;
                    }
                    res2 = (((a[j].res0 + a[j].res1 + a[j].res2) % mod) * ((a[j + 1].res0 + a[j + 1].res1 + a[j + 1].res2) % mod)) % mod;
                    res2 = (res2 - res1 - res0 + 2 * mod) % mod;
                    a[j].res0 = res0;
                    a[j].res1 = res1;
                    a[j].res2 = res2;
                    a[j].r = a[j + 1].r;
                    a.erase(a.begin() + j + 1);
                    ok = 1;
                    break;
                }
            }
        }
    }
    cout << (((a[0].res0 + a[0].res1) * power(2, lh - 1)) % mod + a[0].res2) % mod << endl;
    
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}