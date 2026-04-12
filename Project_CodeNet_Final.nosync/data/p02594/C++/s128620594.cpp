#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define pb push_back
#define endl "\n" // TODO: remove
#define int long long

const int N = (int)(1e6) + 322;
const long long inf = (long long)(2e18) + 322;
const int mod = (int)(1e9) + 7; // check modulo


void solve() {
    int x; cin >> x;
    if (x >= 30) cout << "Yes";
    else cout << "No";

}

signed main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;// cin >> test;
    for(int t = 1; t <= test; ++t) {
        solve();
    }
    return 0;
}

