#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> rem(m, -1);
    vector<ll> ans(m+2, 0);
    ll a = x;
    ans[1] = a;
    rem[a] = 0;

    int i = 1;
    n--;
    while (n > 0) {
        a = (a * a) % m;
        if (rem[a] >= 0)
            break;
        rem[a] = i;
        ans[i+1] = ans[i] + a;
        n--; i++;
    }
    ll score_loop = ans[i] - ans[rem[a]];
    ll len_loop = i - rem[a];

    cout << ans[i] + (n / len_loop) * score_loop
        + ans[(int)(n % len_loop) + rem[a]] - ans[rem[a]] << endl;
    return 0;
}
