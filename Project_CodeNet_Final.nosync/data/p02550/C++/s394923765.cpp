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

void solve() {
    ll n;
    int x, m;
    cin >> n >> x >> m;

    vector<int> cnt(m, 0);
    vector<int> cycle;
    int cur = x;
    ll ans = 0;

    while (n > 0) {
        cnt[cur]++;

        if (cnt[cur] == 2) cycle.push_back(cur);
        else if (cnt[cur] == 3) break;

        ans += cur;
        n--;

        cur = (1LL * cur * cur) % m;
    }
    

    if (!cycle.empty()) {
        ll cycle_sum = 0;
        for (int &el : cycle) {
            cycle_sum += el;
        }

        ll p = n / cycle.size();
        ll q = n % cycle.size();
        ans += p * cycle_sum;

        fori (i, 0, q) {
            ans += cycle[i];
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

