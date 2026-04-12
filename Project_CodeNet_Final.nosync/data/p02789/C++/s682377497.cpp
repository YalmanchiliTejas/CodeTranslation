#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <time.h>
#include <random>
#include <string>
#include <cassert>
#include <vector>
#include <ostream>
#include <istream>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

#define int long long
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define ld long double

#define LOCAL

#ifdef LOCAL
    #define dbg(x) cout << #x << " : " << (x) << "\n";
#else
    #define dbg(x)
#endif

ostream& operator << (ostream &a, const vector<int> &b) {
    for (auto k : b) cout << k << " ";
    cout << "\n";
    return a;
}

const int INF = 1e18;
//const int mod = 2600000069;
//const int p = 179;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (n == m) cout << "Yes\n";
    else cout << "No\n";
}
/*
*/
