#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<int>;

#define rep(i, n)  for(int (i) = 0; (i) < (n); ++(i))
#define rrep(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define Sort(a)    sort(a.begin(), a.end())
#define gSort(a)   sort(a.begin(), a.end(), greater<int>())
#define pout(n, a) cout << fixed << setprecision(n) << (a)
#define Cast(dig, n) static_cast<std::bitset<(dig)>>(n)

const int INF = 2147483647;
const ll  MOD = 1000000007;

int main() {
    int a, b, ab, x, y;
    cin >> a >> b >> ab >> x >> y;

    int ans = 0;

    if((a + b) <= (ab * 2)) {
        ans = (a * x) + (b * y);
    }else {
        int mn = min(x, y);
        int mx = max(x, y);

        // abのみで買いそろえる
        ans = ab * (mx * 2);

        // abと単体で揃える
        int tmp = ab * (mn * 2);

        if(mx == x) tmp += a * (mx - mn);
        else        tmp += b * (mx - mn);

        ans = min(ans, tmp);
    }

    cout << ans;
}