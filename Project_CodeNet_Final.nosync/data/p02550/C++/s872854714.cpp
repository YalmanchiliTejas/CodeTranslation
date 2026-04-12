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

const ll INF = 1e18 + 5, NMAX = 2e5 + 5, MOD = 998244353, N = 1e9 + 5, LOG = 25;
const ld EPS = 1e-8, pi = 3.14159265358979323846;

ll sum(vector<ll> &v, int l, int r) {
    ll sum = 0;
    for(int i = l; i <= r; ++i) sum += v[i];
    return sum;
}

signed main() {
    fast_work

    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> v;
    v.pb(x);

    for(int i = 1; i < n; ++i) {

        ll next = v.back() * v.back() % m;

        for(int j = 0; j < i; ++j) {
            if(v[j] == next) {
                ll s = sum(v, j, i - 1);

                ll cnt = (n - i) / (i - j);
                ll ost = (n - i) % (i - j);

                cout << sum(v, 0, i - 1) + s * cnt + sum(v, j, j + ost - 1);
                return 0;
            }
        }

        v.push_back(next);
    }

    cout << sum(v, 0, n - 1);
}
