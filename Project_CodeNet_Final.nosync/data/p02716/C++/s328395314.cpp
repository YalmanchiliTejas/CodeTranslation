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
typedef long long int i64;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;
using namespace std::chrono;

//const i64 mod = 1000000007ll;
const i64 smod = 998244353ll;
const i64 inf = 1'000'000'000'000'000'000ll + 7;

const double eps = 1e-8;

const i64 MAXN = 200'000 + 6;

i64 n;
i64 a[MAXN];
i64 ps[MAXN];
i64 pre[MAXN];
i64 post[MAXN];

void fillps() {
    ps[0] = a[0];
    ps[1] = a[1];

    for (i64 i = 2; i < n; i++) {
        ps[i] = a[i] + ps[i - 2];
    }
}

void fillpre(i64* pre) {
    pre[0] = max(a[0], a[1]);

    for (i64 i = 2; i < n; i += 2) {
        pre[i] = max(ps[i], pre[i - 2] + a[i + 1]);
    }
}


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed);

    cin >> n;

    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }

    fillps();
    fillpre(pre);

    reverse(a, a + n);
    fillps();
    fillpre(post);

    if (n % 2 == 0) {
        i64 R = pre[n - 2];
        cout << R << endl;
        return 0;
    }

    i64 R = pre[n - 1];
    for (i64 i = 0; i < n; i += 2) {
        i64 j = n - 1 - i;
        i64 t = (i ? pre[i - 2] : 0) + (j ? post[j - 2] : 0);
        R = max(R, t);
    }

    cout << R << endl;


    return 0;
}