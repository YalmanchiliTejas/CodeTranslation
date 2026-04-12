#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <limits>
#include <numeric>

using namespace std;
typedef long long int ll;
typedef long double ld;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }                   // 最大公約数
ll lcm(ll a, ll b) { return a * b / gcd(a, b); };                      // 最小公倍数
ll getDigit(ll num) { return log10(num) + 1; }                         // 桁数
ll digitSum(ll n) { return (n < 10) ? n : digitSum(n / 10) + n % 10; } // 各桁の和
#define pb push_back
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repn(i, n) for (ll i = 1; i <= n; i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(), (x).end()

void Main()
{
    int n;
    cin >> n;
    int x = 800 * n;
    int y = (int)(n / 15) * 200;
    cout << x - y << endl;
    return;
}

signed main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
