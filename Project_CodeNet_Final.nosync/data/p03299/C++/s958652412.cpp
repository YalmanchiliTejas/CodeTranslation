#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

typedef pair<long, int> item;
item zeroSum = {MAX_LONG, -1};

item sum(item a, item b) {
    if (a.first < b.first || a.first == b.first && a.second < b.second) {
        return a;
    } else {
        return b;
    }
}

vector<item> sums;

int size;

item sum(int l, int r, int n, int L, int R) {
    if (l >= R || L >= r) return zeroSum;
    if (L >= l && R <= r) {
        return sums[n];
    }
    int M = (L + R) >> 1;
    return sum(sum(l, r, 2 * n + 1, L, M), sum(l, r, 2 * n + 2, M, R));
}

void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    sums.assign(2 * size, zeroSum);
}

void init(vector<item> a) {
    int n = a.size();
    init(n);
    size = 1;
    while (size < n) size *= 2;
    sums.assign(2 * size, zeroSum);
    for (int i = 0; i < n; i++) {
        sums[size - 1 + i] = a[i];
    }
    for (int i = size - 2; i >= 0; i--) {
        sums[i] = sum(sums[2 * i + 1], sums[2 * i + 2]);
    }
}

item sum(int l, int r) {
    return sum(l, r, 0, 0, size);
}

// -----


#define MOD 1000000007

long sum(long a, long b) { return (a + b) % MOD; }

long minus(long a, long b) { return (a - b + MOD) % MOD; }

long mult(long a, long b) { return (a * b) % MOD; }

long pow(long a, long b) {
    long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

// ---


int N = 0;
vector<vector<int>> g(110);
vector<long> h(110);
vector<long> w(110);

int build_tree(int l, int r) {
//    cout << l << " " << r << "\n";
    int X = N++;
    auto m = sum(l, r);
    h[X] = m.first;
    w[X] = r - l;
    if (m.second > l) {
//        cout << " " << l << " " << r << "->" << l << " " << m.second << "\n";
        g[X].push_back(build_tree(l, m.second));
    }
    while (m.second < r - 1) {
        auto mm = sum(m.second + 1, r);
//        cout << mm.second << "\n";
        if (mm.first == m.first) {
            if (mm.second > m.second + 1) {
//                cout << " " << l << " " << r << "->" << m.second + 1 << " " << mm.second << "\n";
                g[X].push_back(build_tree(m.second + 1, mm.second));
            }
            m = mm;
        } else {
//            cout << " " << l << " " << r << "->" << m.second + 1 << " " << r << "\n";
            g[X].push_back(build_tree(m.second + 1, r));
//            cout << " 333\n";
            break;
        }
    }
//    cout << l << " " << r << "\n";
    return X;
}

vector<long> da;
vector<long> db;

void calc(int x, long hh) {
    int k = w[x];
    long pa = 1;
    long pb = 1;
    for (auto y: g[x]) {
        calc(y, h[x]);
        pa = mult(pa, mult(2, da[y]));
        pb = mult(pb, sum(db[y], mult(2, da[y])));
        k -= w[y];
    }
    da[x] = mult(pow(2, (h[x] - hh - 1)), pa);
    db[x] = mult(da[x], 2);
    db[x] = sum(db[x], mult(pb, pow(2, k)));
    db[x] = minus(db[x], mult(2, pa));
//    cout << w[x] << " " << (h[x] - hh) << " " << da[x] << " " << db[x] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    init(a);

    int root = build_tree(0, n);
//    cout << root << "\n";

    da.resize(N);
    db.resize(N);
    calc(root, 0);
    cout << db[root] << "\n";

    return 0;
}