#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 1;
    x -= y + 2 * z;
    cout << ans + x /(y + z) << endl;
    return 0;
}