#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define show(x) cout << #x << " = " << x << endl;
int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = 0;
    if (a >= k) {
        cout << 1 << endl;
    } else {
        if (a <= b) {
            cout << -1 << endl;
        } else {
            cout << 1 + (k - a + a - b - 1) / (a - b) * 2 << endl;
        }
    }
}
