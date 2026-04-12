#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
 freopen("input","r",stdin);
 freopen("output","w",stdout);
*/

ll MOD = 1E9 + 7;

ll DP[10010][110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int d;
    cin >> d;
    memset(DP, 0, sizeof(DP));
    int l = s.size();
    DP[l][0] = 1;
    for (int i = l - 1;i >= 0;i--) {
        for (int j = 0;j <= 9;j++) {
            for (int k = 0;k < d;k++) {
                DP[i][(j + k) % d] += DP[i + 1][k];
                DP[i][(j + k) % d] %= MOD;
            }
        }
    }
    int prefix = 0;
    ll sol = 0;
    for (int i = 0;i < l;i++) {
        int x = s[i] - '0';
        int y = x;
        if (i == l - 1) y = x + 1;
        for (int j = 0;j < y;j++) {
            int crt = prefix + j;
            int rem = (d - (crt % d)) % d;
            sol += DP[i + 1][rem];
            sol %= MOD;
        }
        prefix += x;
        prefix %= d;
    }
    // exclude 0
    sol += MOD - 1;
    cout << sol % MOD << endl;
    return 0;
}