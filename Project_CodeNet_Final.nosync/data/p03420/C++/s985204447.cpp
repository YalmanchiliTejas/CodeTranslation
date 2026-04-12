#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;

int main() {
    long ans = 0;
    long n, k;
    cin >> n >> k;
    
    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }
    
    for (long b = k + 1; b <= n; b++) {
        long c = b - k;
        long m = (n + 1) / b;
        ans += c * m;
        if (k + b * m <= n) {
            ans += n - (k + b * m) + 1;
        }
    }
    
    cout << ans << endl;
}
