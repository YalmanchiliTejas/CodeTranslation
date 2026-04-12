// 'That's all it is. A leap of faith'

#include <bits/stdc++.h>

#define append push_back
#define L first
#define R second

using namespace std;
using ll = long long;

const int N = 1e5 + 3;
const long long M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 5;
const int logN = 22, BL = 400;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

template<typename Type>
long long sz(Type x) {
    return ll(x.size());
}

void debug() {
	cerr << "\n";
}
template<typename Type1, typename... Type2>
void debug(Type1 a, Type2... b) {
    cerr << a << " ";
    debug(b...);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n, X, m; cin >> n >> X >> m;

    vector<long long> a(m * 2 + 1), f(m * 2 + 1);
    map<long long, long long> u;

    a[1] = X, u[X] = 1, f[1] = X;

    long long st = 0, nd = 0, rd = 0, x = 0, y = 0, z = 0;

    for(long long i = 2; i <= m * 2; i++) {
        a[i] = (a[i - 1] * 1ll * a[i - 1]) % m;
        f[i] = f[i - 1] + a[i];

        if(u.find(a[i]) != u.end()) {
            x = u[a[i]] - 1, y = i - u[a[i]], z = (n - x) % y;
            st = f[x], nd = (f[x + y] - f[x]) * ((n - x) / y), rd = f[x + z] - f[x];
            break;
        }

        u[a[i]] = i;
    }

    debug(st, nd, rd);

    if(n <= m * 2) cout << f[n];
    else cout << st + nd + rd;

    return 0;
}
