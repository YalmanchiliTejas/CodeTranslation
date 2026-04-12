#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdint.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>

#include <algorithm>
#include <functional>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>

#define sqr(x) (x) * (x)

typedef unsigned int u32;
typedef int i32;
typedef unsigned long long int u64;
typedef long long int i64;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;
using namespace std::chrono;

// const i64 mod = 1'000'000'000ll + 7;
const i64 mod = 998244353ll;

//const i64 inf = mod;

const long double eps = 1e-8;

struct segtree {
    typedef i64 type;
    const type zero = 0;

    vector<type> st;

    void init(i64 size) {
        i64 n = 1;
        while (n < size) {
            n *= 2;
        }
        st.assign(n * 2, zero);
    }

    void add(i64 l, i64 r, type v, i64 x, i64 lx, i64 rx) {
        if (r <= lx || rx <= l) {
            return;
        }

        if (l <= lx && rx <= r) {
            st[x] += v;
            st[x] %= mod;
            return;
        }

        i64 mx = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, mx);
        add(l, r, v, 2 * x + 2, mx, rx);
    }

    void add(i64 l, i64 r, type v) {
        add(l, r, v, 0, 0, st.size() / 2);
    }

    type get(i64 i, i64 x, i64 lx, i64 rx) {
        if (rx - lx == 1) {
            return st[x];
        }

        i64 mx = (lx + rx) / 2;
        if (i < mx) {
            return (get(i, 2 * x + 1, lx, mx) + st[x]) % mod;
        }
        else {
            return (get(i, 2 * x + 2, mx, rx) + st[x]) % mod;
        }
    }

    type get(i64 i) {
        return get(i, 0, 0, st.size() / 2);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed); cerr.precision(15); cerr.setf(ios::fixed);

    i64 n, x, m;
    cin >> n >> x >> m;

    vector<i64> a;
    a.push_back(x);

    map<i64, i64> q;
    q[x] = 0;


    i64 i = 1;
    i64 s = x;

    i64 t = 0;
    i64 j = 0;

    while (i < n) {
        i64 v = sqr(a.back()) % m;
        if (q.count(v)) {
            t = i - q[v];
            j = q[v];
            break;
        }
        a.push_back(v);
        q[v] = i;
        s += a.back();
        i += 1;
    }

    if (t) {
        i64 st = 0;
        for (i64 i = j; i < a.size(); i++) {
            st += a[i];
        }

        i64 p = (n - i) / t;
        i += p * t;
        s += p * st;
    }


    while (i < n) {
        i64 v = sqr(a.back()) % m;
        a.push_back(v);
        s += a.back();
        i += 1;
    }

    cout << s << endl;
    

    return 0;
}