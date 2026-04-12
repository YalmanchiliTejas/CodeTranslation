#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int K;
    cin >> n >> K;

    auto count = [&](int n, int m, int r) {
        if (r == 0) {
            return n;
        }
        ++n;
        int res = (n / m) * r;
        int rem = n % m;
        res += min(rem, r);
        res = n - res;
        // cout << n << " " << m << " " << r << " " << res << endl;
        return res;
    };

    long long res = 0;
    for (int i = K + 1; i <= n; ++i) {
        res += count(n, i, K);
    }

    cout << res << '\n';

    return 0;
}