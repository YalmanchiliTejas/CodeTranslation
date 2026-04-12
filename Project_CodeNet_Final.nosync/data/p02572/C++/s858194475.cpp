#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define st first
#define nd second

const int MAXN = 1e6 + 5, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18, MOD = 1e15 + 37;
const ld PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(13) << fixed;

    //////////////////////////////////////////
    //////////////////////////////////////////

    int n;
    cin >> n;
    int sum = 0, sum_squares = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum = (sum + a) % mod;
        sum_squares = (0LL + sum_squares + 1LL * a * a) % mod;
    }

    int square_sum = 1LL * sum * sum % mod;
    int double_res = ((square_sum - sum_squares) % mod + mod) % mod;
    cout << 500000004LL * double_res % mod << "\n";
}
