#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using llong = long long;

llong ans;
llong n;
llong d[200005];
llong sum[200005];
map<llong, llong> s2il;
map<llong, llong> s2ir;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    s2il[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + d[i];
        
        s2ir[sum[i]] = i;
        if(s2il.count(sum[i]) == 0) {
            s2il[sum[i]] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        llong l1 = i - s2il[sum[i]];
        llong l2 = s2ir[sum[i]] - i;
        ans = max({ans, l1, l2});
    }

    cout << ans << endl;

    return 0;
}

