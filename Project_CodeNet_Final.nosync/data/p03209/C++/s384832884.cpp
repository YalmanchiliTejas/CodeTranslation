#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
#include <list>
#include <set>

#define llong long long int

using namespace std;

int n;
llong x, p[51], l[51];

llong search (int n, llong cnt, llong ans) {
    //cout << cnt << endl;
    --cnt;
    //cout << cnt << endl;
    if (cnt == 0) return ans;
    if (cnt - l[n - 1] >= 0) {
        ans += p[n - 1];
        cnt -= l[n - 1];
    } else {
        return search(n - 1, cnt, ans);
    }
    if (cnt == 0) return ans;
    --cnt;
    ++ans;
    //cout << "hello" << endl;
    //cout << ans << " " << cnt << endl; 
    if (cnt == 0) return ans;
    if (cnt - l[n - 1] >= 0) {
        ans += p[n - 1];
        cnt -= l[n - 1];
    } else {
        return search(n - 1, cnt, ans);
    }
    if (cnt == 0) return ans;
    --cnt;
    if (cnt == 0) return ans;
}

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    p[0] = 1;
    l[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = 2 * p[i - 1] + 1;
        l[i] = 2 * l[i - 1] + 3;
    }

    cout << search(n, x, 0) << endl;
    return 0;
}