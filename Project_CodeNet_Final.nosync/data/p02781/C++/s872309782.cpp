#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int comb(int n, int k) {
    if (k < 0 || n < k)
        return 0;
    int t = 1;
    for (int i = 0; i < k; ++i) {
        t *= n;
        n--;
    }
    for (int i = 1; i <= k; ++i) {
        t /= i;
    }
    return t;
}

int main() {
    string n;
    int k, ans = 0;
    cin >> n >> k;
    for (int i = n.size() - 1, s = 0; i >= 0 && k > 0; --i, ++s) {
        if (n[s] == '0')
            continue;
        ans += (n[s] - '0' - 1) * comb(i, k - 1) * pow(9, k - 1);
        if (k == 1)
            ans++;
        ans += comb(i, k) * pow(9, k);
        k--;
    }
    cout << ans << endl;

    return 0;
}