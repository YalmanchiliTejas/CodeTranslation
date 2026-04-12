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

const i64 mod = 1'000'000'000ll + 7;
//const i64 smod = 998244353ll;
//const i64 inf = 1'000'000'000'000'000'000ll + 7;
//const i64 inf = 1'000'000'007;

const double inf = 1e9;

const long double eps = 1e-8;



int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed); cerr.precision(15); cerr.setf(ios::fixed);

    i64 n;
    cin >> n;
    vector<i64> a(n);

    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 s = 0;
    for (i64 i = 0; i < n; i++) {
        s += a[i];
        s %= mod;
    }

    i64 R = 0;
    for (i64 i = 0; i < n; i++) {
        s = (s - a[i] + mod) % mod;
        R += (s * a[i]) % mod;
        R %= mod;
    }

    cout << R << endl;

    return 0;
}