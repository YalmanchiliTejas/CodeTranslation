#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <unordered_map>
#include <map>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int s = 100 * r + 10 * g + b;
    if (s % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
