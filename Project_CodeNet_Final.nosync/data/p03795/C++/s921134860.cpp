#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define int long long

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} SETUP;

signed main() {
    int n;
    cin >> n;
    int x = n * 800;
    int y = n / 15 * 200;
    cout << x - y << endl;
}
