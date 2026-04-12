/* include */
#include "bits/stdc++.h"
/* namespace */
using namespace std;
/* using */
// data type
using ll = long long;
using ld = long double;
// vector
using vi = vector<int>;
using vd = vector<double>;
using vll = vector<ll>;
using vld = vector<ld>;
using vs = vector<string>;
/* define */
#define pb(x) push_back(x)          // push_back
#define all(x) x.begin(), x.end()   // all_range
#define PI M_PI                     // PI
#define gcd(a, b) __gcd(a, b)       // 最大公約数
#define lcm(a, b) (a / gcd(a, b) * b) // 最小公倍数

void Main(void)
{
    int x;
    cin >> x;
    if (30 <= x)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main(int argc, char* argv[])
{
    ll now_time = clock();
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    if (argc == 2 && *argv[1] == 't')
    {
        // 時間計測
        cout << endl;
        cout << "Execution Time : " << 1.0 * (clock() - now_time) / CLOCKS_PER_SEC << "[sec]" << endl;
    }
    else
    {
        // 通常処理
    }

    return 0;
}  
