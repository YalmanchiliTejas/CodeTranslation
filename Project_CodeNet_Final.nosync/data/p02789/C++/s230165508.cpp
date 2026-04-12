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

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define ld double
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
//#define len length()
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect


void solve() {
    int n, m;
    cin >> n >> m;
    cout << (n == m ? "Yes" : "No");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
