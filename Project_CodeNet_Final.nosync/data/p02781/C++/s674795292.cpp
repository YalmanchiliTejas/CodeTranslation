#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>

/*#pragma GCC optimize("O3")
#pragma target("avx2")
#pragma GCC optimize("unroll-loops")*/

using namespace std;

/*random_device rd;
mt19937 gen(rd());*/

typedef long long ll;
typedef long double ld;

#define int ll
//#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect

const int N = 1e5 + 7;

void solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size(), ans = 0;
    loop1(i, n - 1) {
        if (k == 1) 
            ans += 9;
        if (k == 2)
            ans += 81ll * (i - 1);
        if (k == 3)
            ans += 729ll * (i - 1) * (i - 2) / 2;
    }
    if (k == 1)
        ans += s[0] - '0';
    if (k == 2) {
        ans += 9ll * (n - 1) * (s[0] - '1');
        for (int i = 1; i < n; ++i)
            if (s[i] > '0') {
                ans += (s[i] - '0') + 9ll * (n - i - 1);
                break;
            }
    }
    if (k == 3) {
        ans += 81ll * (n - 1) * (n - 2) / 2 * (s[0] - '1');
        for (int i = 1; i < n; ++i)
            if (s[i] > '0') {
                ans += 9ll * (s[i] - '1') * (n - i - 1) + 81ll * (n - i - 1) * (n - i - 2) / 2;
                for (int j = i + 1; j < n; ++j)
                    if (s[j] > '0') {
                        ans += (s[j] - '0') + 9ll * (n - j - 1);
                        break;
                    }
                break;
            }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}