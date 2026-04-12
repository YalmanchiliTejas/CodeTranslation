#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdint.h>
#include <string.h>

#include <unordered_set>

#define _USE_MATH_DEFINES
#include <math.h>


#include <vector>
#include <list>

#include <set>
#include <map>

#include <unordered_map>

#include <queue>

#include <string>

#include <vector>

#define sqr(x) (x) * (x)

#include <algorithm>
#include <functional>

#include <bitset>

#include <functional>

#include <chrono>

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

struct less_key
{
    bool operator() (pair<i64, i64> p1, pair<i64, i64> p2)
    {
        return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
    }
};

struct pair_hash {
public:
    std::size_t operator()(const std::pair<u64, u64> &x) const
    {
        return std::hash<u64>()(x.first) ^ std::hash<u64>()(x.second);
    }
};
#include <random>

const i64 mod = 1000000007ll;
const i64 smod = 999983;
const i64 inf = mod;

const double eps = 1e-10;

// del

const i64 MAXN = 22;

i64 n;
i64 a[MAXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed);

    cin >> n;

    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 R = 1;
    for (i64 i = 1; i < n; i++) {
        bool f = true;
        for (i64 j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                f = false;
                break;
            }
        }
        if (f) {
            R++;
        }
    }

    cout << R << endl;

    return 0;
}
