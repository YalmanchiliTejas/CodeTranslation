#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, a, n) for (int i = a; i < (n); i++)
#define all(in) in.begin(), in.end()
const int INF = 1e9;
const long long MOD = 1e9 + 7;

int main() {
    long long a, b, x;
    cin >> a >> b >> x;
    long long ans = x + (max(x - b, 0ll) / (a - b)) % MOD * (b % MOD);
    cout << ans % MOD << endl;
    return 0;
}
