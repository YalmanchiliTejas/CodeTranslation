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

const int MAX = 2e5 + 15;
const ll INF = (ll) 1e18;
ll arr[MAX];
ll cnt[MAX];
ll memo[MAX][5];
bool visited[MAX][5];
int n;
int max_jumps;

ll roll(int idx, int jumped) {
    if ((n & 1) && idx == n && jumped == 0) {
        return 0;
    }
    if (idx > n) {
        return 0;
    }
    ll &ans = memo[idx][jumped];
    if (visited[idx][jumped]) {
        return ans;
    }
    visited[idx][jumped] = true;
    ans = roll(idx + 2, jumped) + arr[idx];
    if (jumped < max_jumps) {
        ans = max(ans, roll(idx + 1, jumped + 1));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    fori (i, 1, n + 1) cin >> arr[i];
    arr[n + 1] = -INF;
    ford (i, n, 1) {
        cnt[i] = max(arr[i] + cnt[i + 2], arr[i + 1] + cnt[i + 3]);
    }
    memset(memo, -1, sizeof memo);
    if (n % 2 == 0) {
        max_jumps = 1;
        cout << roll(1, 0) << endl;
    }
    else {
        max_jumps = 2;
        cout << roll(1, 0) << endl;
    }
    return 0;
}

