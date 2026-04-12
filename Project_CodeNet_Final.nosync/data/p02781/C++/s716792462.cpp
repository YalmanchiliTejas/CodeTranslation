#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdint.h>
#include <string.h>

//#define _USE_MATH_DEFINES
//#include <math.h>

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
typedef int i64;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;
using namespace std::chrono;

const i64 mod = 1000000007ll;
const i64 smod = 998244353ll;
const i64 inf = 1000000007; // 10000000000000007ll;

const double eps = 1e-8;

const i64 MAXN = 300004;

string n;
i64 k;

string d9[102];

i64 solve(string n, i64 k) {
    if (k == 0) {
        //cerr << n << " " << k << ": " << 1 << endl;
        return 1;
    }

    i64 j = 0;
    while (j < n.size() && n[j] == '0') {
        j += 1;
    }
    n = n.substr(j);

    if (k > n.size()) {
        //cerr << n << " " << k << ": " << 0 << endl;
        return 0;
    }

    i64 R = 0;
    for (i64 i = n.size() - 1; i >= 0; i--) {
        string t = n.substr(i + 1);
        if (i) {
            t = d9[t.size()];
            R += 9 * solve(t, k - 1);
        }
        else {
            if (n[i] == '0') {
                R += solve(t, k);
            }
            else {
                R += solve(t, k - 1);
                t = d9[t.size()];
                R += (n[i] - '1') * solve(t, k - 1);
            }
        }
        //R += (i ? 9 : n[i] - '0') * solve(t, k - 1);
    }
    //cerr << n << " " << k << ": " << R << endl;
    return R;
}

i64 cnt(i64 v) {
    i64 R = 0;
    while (v) {
        if (v % 10) {
            R += 1;
        }
        v /= 10;
    }
    return R;
}

i64 test(i64 n, i64 k) {
    i64 R = 0;
    for (i64 i = 1; i <= n; i++) {
        if (cnt(i) == k) {
            R += 1;
        }
    }
    return R;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed);

    for (i64 i = 1; i < 102; i++) {
        stringstream ss;
        ss << d9[i - 1] << '9';
        d9[i] = ss.str();
    }

    //cerr << test(1002, 3) << endl;

    cin >> n >> k;

    i64 R = 0;
    R = solve(n, k);
    cout << R << endl;
    return 0;
}