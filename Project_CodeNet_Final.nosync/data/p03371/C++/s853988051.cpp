/* atcoder */
#include "bits/stdc++.h"
using namespace std;

/* typedef */
/* long系 */
typedef long long ll;   // long long
typedef long double ld; // long double
/* vector系 */
typedef vector<int> vi;                    // intのvector
typedef vector<double> vd;                 // doubleのvector
typedef vector<ll> vll;                    // llのvector
typedef vector<ld> vld;                    // ldのvector
typedef vector<vector<int>> vvi;           // intの2次元vector
typedef vector<vector<double>> vvd;        // doubleの2次元vector
typedef vector<vector<ll>> vvll;           // llの2次元vector
typedef vector<vector<ld>> vvld;           // ldの2次元vector
typedef vector<pair<int, int>> vi_i;       // i_iのvector
typedef vector<pair<double, double>> vd_d; // d_dのvector
typedef vector<pair<ll, ll>> vl_l;         // l_lのvector
typedef vector<pair<ld, ld>> vld_ld;       // ld_ldのvector
typedef vector<string> vs;                 // stringのvector
/* pair系 */
typedef pair<int, int> i_i;       // int同士のpair
typedef pair<double, double> d_d; // double同士のpair
typedef pair<ll, ll> l_l;         // ll同士のpair
typedef pair<ld, ld> ld_ld;       // ld同士のpair

/* define */
#define all(v) v.begin(), v.end() // コンテナ全体
#define PI (acos(-1))             // 円周率pi

/* stringstream */
stringstream ss;
stringstream init_ss; // save default formatting

/* upper, lower */
struct ToUpper
{
    char operator()(char c)
    {
        return toupper(c);
    }
};
struct ToLower
{
    char operator()(char c)
    {
        return tolower(c);
    }
};

/* main */
void Main(void)
{
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans;
    if (a + b < 2 * c)
    {
        ans = a * x + b * y;
    }
    else
    {
        ll cn = min(x, y);
        ll ans1 = 2 * c * cn + a * abs(x - cn) + b * abs(y - cn);
        ll ch = max(x, y);
        ll ans2 = 2 * c * ch;
        ans = min(ans1, ans2);
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();

    return 0;
}
