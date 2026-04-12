#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int MAXN = 111;
const int P = 1e9 + 7;

int dp[MAXN][MAXN];

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}


void mul(int &a, int b) {
    ll c = (ll)a * b;
    c %= P;
    a = c;
}

int binPow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = binPow(a, b / 2);
    mul(res, res);
    if (b & 1) {
        mul(res, a);
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    ++n;

    vector<int> h(n);

    set<int> setik;

    h[0] = 1;
    for (int i = 1; i < n; ++i) {   
        cin >> h[i];
    }

    for (int i = 0; i < n; ++i) {
        setik.insert(h[i]);
    }

    vector<int> u;

    for (int s : setik) {
        u.push_back(s);
    }

    int m = sz(u);

    dp[0][0] = 2;

    for (int i = 1; i < n; ++i) {

        int pos = -1;

        if (h[i] == 1) {
            for (int j = 0; j < m; ++j) {
                add(dp[i][0], dp[i - 1][j]);
            }
            mul(dp[i][0], 2);
            continue;
        }

        for (int j = 0; j < m; ++j) {
            if (u[j] == h[i - 1]) {
                pos = j;
            }

            if (h[i - 1] >= h[i]) {
                if (u[j] < h[i]) {
                    add(dp[i][j], dp[i - 1][j]);
                } else if (u[j] == h[i]) {
                    for (int k = j; k < m; ++k) {
                        add(dp[i][j], dp[i - 1][k]);
                    }
                    mul(dp[i][j], 2);
                }
            } else {
                if (u[j] < h[i - 1]) {
                    int cur = dp[i - 1][j];
                    mul(cur, binPow(2, h[i] - h[i - 1]));
                    add(dp[i][j], cur);
                } else if (u[j] < h[i]) {
                    int cur = dp[i - 1][pos];
                    mul(cur, 2);
                    mul(cur, binPow(2, u[j + 1] - u[j]) - 1);
                    mul(cur, binPow(2, h[i] - u[j + 1]));
                    add(dp[i][j], cur);
                    // cout << pos << endl;
                    // cout << i << " " << dp[i][j] << endl;
                } else if (u[j] == h[i]) {
                    int cur = dp[i - 1][pos];
                    mul(cur, 2);
                    add(dp[i][j], cur);
                }
            }
        }
    }

    int res = 0;

    for (int j = 0; j < m; ++j) {
        add(res, dp[n - 1][j]);
    }

    mul(res, (P + 1) / 2);

    cout << res << endl;


    return 0;
}