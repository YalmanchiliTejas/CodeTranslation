/* COMPETITIVE PROGRAMMING C++ TEMPLATE */

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <iomanip>

#define all(x) x.begin(), x.end()
#define MOD 998244353
#define debug(x) cout << #x << " = " << x << "\n"

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
void solve()
{
    //code here.
    int x;
    cin >> x;
    if (x >= 30)
    {
        cout << "Yes";
        return;
    }
    cout << "No";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    //cin >> T; // If only one test case then you can comment this line out.

    while (T--)
    {
        solve();
    }
    return 0;
}