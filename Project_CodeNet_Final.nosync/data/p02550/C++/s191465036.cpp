#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
//#define mod 998244353
#define MAXM 100001
ll first[MAXM];
bool used[MAXM];
ll ans[MAXM];
int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    int count = 1; //周期
    memset(used, false, sizeof(used));
    ll ret = 0;
    ans[0] = 0;
    while (!used[x]) {
        used[x] = true;
        first[x] = count;
        ret += x;
        ans[count] = ret;
        x = x * x % m;
        if (n == count) {
            cout << ret << endl;
            return 0;
        }
        count++;
    }
    ll syuuki = count - first[x];
    //cout << syuuki << endl;
    //cout << count << endl << ans[count] << endl;
    ll syuukisum = ans[count - 1] - ans[first[x] - 1];
    //cout << syuukisum << endl;
    ll tempret = ans[first[x] - 1] + ((n - first[x] + 1) / syuuki) * syuukisum;
    ll rest = (n - first[x] + 1) % syuuki;
    for (int i = 1; i <= rest; i++) {
        tempret += x;
        x = x * x % m;
    }
    cout << tempret << endl;
    return 0;
}