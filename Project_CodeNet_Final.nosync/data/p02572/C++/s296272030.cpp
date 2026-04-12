# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <chrono>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <cassert>
# include <array>
# include <tuple>
# include <cctype>
# include <unistd.h>
# include <unordered_map>
# include <unordered_set>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define fast_work {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

const ll INF = 1e9 + 5, NMAX = 2e5 + 5, MOD = 1000000007, N = 1e9 + 5, LOG = 25;
const ld EPS = 1e-8, pi = 3.14159265358979323846;

ll a[NMAX];

signed main() {
    fast_work
    string s, t;
    int n;
    cin >> n;

    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    ll answer = 0;

    sum %= MOD;

    for(int i = 0; i < n; ++i) {
        sum = (sum - a[i] + MOD) % MOD;
        ll add = (a[i] * sum) % MOD;
        answer = (answer + add) % MOD;
    }

    cout << answer;
}
