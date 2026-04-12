#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef unsigned int u32;
typedef int i32;
typedef unsigned long long int u64;
typedef long long int i64; // 9e18
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

//const double PI = 3.141592653589793238463;
//const int MAXN = 1000500;
//const int MAXVALUE = 1000000500;
//const long double EPS = 1e-7;
const i64 INF = 1e18;
i64 mod = 1e9 + 7;


i64 T, n, m, k;
//vector <vector<i64>> a;
//vector <i64> a;
//vector <i64> b;
//vector <i64> dp;

i64 norm(i64 d, i64 MOD) {
    return ((d % MOD) + MOD) % MOD;
}

i64 add_m(i64 x, i64 y, i64 MOD) {
    return norm(norm(x, MOD) + norm(y, MOD), MOD);
}

i64 mul_m(i64 x, i64 y, i64 MOD) {
    return norm(norm(x, MOD) * norm(y, MOD), MOD);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(16);


    //cin >> T;
    T = 1;

    for (i64 tt = 0; tt < T; ++tt) {

        cin >> n;
        vector<i64>a(n);
        for (i64 i = 0; i < n; ++i) {
            cin >> a[i];
        }

        i64 res = 0;
        i64 sum = 0;

        for (i64 i = n-1; i >= 1; --i) {
            sum = add_m(sum, a[i], mod);
            res = add_m(res, mul_m(sum, a[i - 1], mod), mod);
        }

        cout << res << endl;

    }
    return 0;
}