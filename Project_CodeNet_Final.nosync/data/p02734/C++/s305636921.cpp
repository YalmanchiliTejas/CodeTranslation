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

const int MAX = 3000 + 5;
const int MOD = 998244353;
int arr[MAX], memo[MAX][MAX][3];
int n, s;

inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int roll(int idx, int sum, int state) {
    if (state == 2) {
        return sum == 0;
    }
    if (sum < 0 or idx > n) {
        return 0;
    }
    int &ans = memo[idx][sum][state];
    if (~ans) {
        return ans;
    }
    ans = 0;
    if (state == 0) {
        int a = roll(idx + 1, sum, state);
        int b = roll(idx + 1, sum, 1);
        int c = roll(idx + 1, sum - arr[idx], 1);
        int d = roll(idx + 1, sum - arr[idx], 2);
        ans = add(add(a, b), add(c, d));
    }
    if (state == 1) {
        int a = roll(idx + 1, sum, state);
        int b = roll(idx + 1, sum, 2);
        int c = roll(idx + 1, sum - arr[idx], state);
        int d = roll(idx + 1, sum - arr[idx], 2);
        ans = add(add(a, b), add(c, d));
    }
    return ans;
}

void solve() {
    cin >> n >> s;
    fori (i, 1, n + 1) cin >> arr[i];
    memset(memo, -1, sizeof memo);
    cout << roll(1, s, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

