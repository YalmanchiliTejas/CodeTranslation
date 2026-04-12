#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// 293206GT
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <unordered_set>
#include <stack>
#include <string>
#include<algorithm>
#include <random>
#include <bitset>
#include <chrono>

typedef long long ll;
//#define int ll
using namespace std;
#define put(a) cout << (a) << '\n'
#define sqr(x) ((x) * (x))
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<pii> vpii;
#define rep(x, y, a) for (int x = (y); x < (int)(a); ++x)
#define all(a) a.begin(), a.end()
#define chkmax(a, b) a = max(a, (b))
#define chkmin(a, b) a = min(a, (b))
#define prev asasdasd
#define next aasdasda
#define left asdasdasdasd
#define right asnabsdkasdl
#define rank asdasdknlasd
#define move asdasdas
#define fname "parray"
#define fin fname".in"
#define fout fname".out"
#define files freopen(fin, "r", stdin);freopen(fout, "w", stdout);
namespace IO {

    template<class A, class B>
    ostream &operator<<(ostream &out, vector<pair<A, B>> a);

    template<class A>
    ostream &operator<<(ostream &out, vector<A> a);

    template<class A, class B>
    ostream &operator<<(ostream &out, pair<A, B> a) {
        out << a.first << " " << a.second;
        return out;
    }

    template<class A, class B>
    ostream &operator<<(ostream &out, vector<pair<A, B>> a) {
        for (pair<A, B> x: a)
            out << x.first << " " << x.second << '\n';
        return out;
    }

    template<class A>
    ostream &operator<<(ostream &out, vector<A> a) {
        for (A x: a) out << x << ' ';
        return out;
    }

    template<class A, class B>
    istream &operator>>(istream &in, pair<A, B> &a) {
        in >> a.first >> a.second;
        return in;
    }

    template<class A>
    istream &operator>>(istream &in, vector<A> &a) {
        for (A &x: a) in >> x;
        return in;
    }
}
using namespace IO;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int x;
    cin >> x;
    put(x>=30?"Yes":"No");
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(30);
//    freopen("input.txt", "r", stdin);
//    files
    int q = 1;
//    cin >> q;
    while (q--) solve();
}

