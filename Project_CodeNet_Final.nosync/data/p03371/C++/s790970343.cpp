#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long mcost = INF;
    int n = max(X, Y);
    rep(i, 0, 2 * n + 1) {
        long long cost = 0;
        cost += i * C;
        int nokoriA = X - i / 2;
        int nokoriB = Y - i / 2;
        if(nokoriA > 0) {
            cost += nokoriA * A;
        }
        if(nokoriB > 0) {
            cost += nokoriB * B;
        }
        if(mcost > cost) {
            mcost = cost;
        }
    }
    cout << mcost << endl;
}
