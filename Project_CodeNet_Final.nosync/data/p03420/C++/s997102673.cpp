#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <complex>
#include <cstring>

using namespace std;

#define FILE_PREFIX "../../../../../../../../CompetitiveProgramming/CF/CF/"
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR((i), 0, (n))
#define ll unsigned int
#define pb push_back

const int N = 3e5*32;
const int MOD = 1e9 + 7;

int n, k;

int main() {
//        freopen(FILE_PREFIX"input.txt", "r", stdin);
    ios :: sync_with_stdio(false);
    cin >> n >> k;
    
    if (k == 0) {
        cout << 1LL * n * n << endl;
        return 0;
    }
    
    long long res = 0;
    for (int b = k + 1; b <= n; ++b) {
        res += (n / b) * (b - k);
        int m = n % b;
        if (m >= k) res += m - k + 1;
    }
    
    cout << res << endl;
    return 0;
}
