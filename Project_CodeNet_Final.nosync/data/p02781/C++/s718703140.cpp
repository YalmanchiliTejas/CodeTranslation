#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

inline int comb(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    if (k == 1) return n;
    if (k == 2) return (n * (n - 1)) / 2;
    return (n * (n - 1) * (n - 2)) / 6;
}

inline int pot(int x, int k) {
    int result = 1;
    fori (i, 0, k) result *= x;
    return result;
}

void solve() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int size = s.size();
    ll ans = 0;
    fori (i, k, size) {
        ans += 1LL * pot(9, k) * comb(i - 1, k - 1);
    }
    int rem_k = k;
    for (int i = 0; i < size && rem_k > 0; i++) {
        int d = s[i] - '0';
        int rem_size = size - i - 1;
        fori (j, 1, d) {
            ans += 1LL * pot(9, rem_k - 1) * comb(rem_size, rem_k - 1);
        }
        if (d > 0 && i > 0) {
            ans += 1LL * pot(9, rem_k) * comb(rem_size, rem_k);
        }
        if (d > 0) {
            rem_k--;
        }
    }
    if (rem_k == 0) ans++;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

