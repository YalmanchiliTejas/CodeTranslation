/*
[abc128] F - Frog Jump
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
int s[MAX_N];
bool used[MAX_N];

ll solve() {
    ll ans = 0;
    for (int d = 1; d < N - 1; d++) {
        ll t = 0;
        for (int k = 0; d < N - 1 - k * d; k++) {
            used[k * d] = true;
            if (used[N - 1 - k * d]) {
                break;
            }
            t += s[k * d] + s[N - 1 - k * d];
            ans = max(ans, t);
        }
        for (int k = 0; k * d < N - 1; k++) {
            used[k * d] = false;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    cout << solve() << endl;

    return 0;
}
