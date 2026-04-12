#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
//#define DEBUG
//#define RANDOM
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x, m;
    // rekurencia sa zacykli po max m krokoch
    cin >> n >> x >> m;
    vector<ll> when(m, -1); // kedy naposledy sme navstivili toto policko
    vector<ll> sum(m, -1); // a aky bol vtedy sucet
    ll ans = 0;
    ll a_now = x;
    ll cycle_len = 0, cycle_sum = 0, pre_len = 0, pre_sum = x;
    // potrebujeme vediet:
    // dlzku cyklu, sucet cyklu, dlzku predperiody a sucet predperiody,
    sum[x] = x;
    when[x] = 0;
    a_now = (a_now * a_now) % m;
    for (int i = 1;; i++)
    {
        if (i >= n)
        {
            cout << pre_sum << "\n";
            return 0;
        }
        if (when[a_now] > -1)
        {
            cycle_len = i - when[a_now];
            cycle_sum = pre_sum - sum[a_now] + a_now;
            pre_len = i;
            break;
        }
        sum[a_now] = pre_sum + a_now;
        pre_sum += a_now;
        when[a_now] = i;
        ll nw = (a_now * a_now) % m;
        a_now = nw;
    }
    ans = pre_sum;
    n -= pre_len;
    ans += cycle_sum * (n / cycle_len);
    n %= cycle_len;
    for (int i = 0; i < n; i++)
    {
        ans += a_now;
        a_now = (a_now * a_now) % m;
    }
    cout << ans << "\n";
    return 0;
}