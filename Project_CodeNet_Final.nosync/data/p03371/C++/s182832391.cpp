/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type Abbreviation ---------- */
using ll = long long;

/* ---------- Constants ---------- */
const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

/* ---------- Short Functions ---------- */
template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    ll X, Y;
    cin >> X >> Y;

    if (A + B >= C * 2) {
        ll cNum = min(X, Y) * 2;
        ll aNum = 0;
        ll bNum = 0;
        if (X > Y) {
            bNum = 0;
            if (A <= C * 2) {
                aNum = X - cNum/2;
            } else {
                cNum = X * 2;
            }
        } else {
            aNum = 0;
            if (B <= C * 2) {
                bNum = Y - cNum/2;
            } else {
                cNum = Y * 2;
            }
        }

        cout << A * aNum + B * bNum + C * cNum << endl;
    } else {
        cout << A * X + B * Y << endl;
    }

    return 0;
}