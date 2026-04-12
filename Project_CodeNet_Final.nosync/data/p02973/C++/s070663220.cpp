#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    deque<int> d;
    rep(i, n) {
        int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if(p == 0) {
            d.push_front(a[i]);
        }
        else {
            d[p-1] = a[i];
        }
    }

    int ans = d.size();

    cout << ans << endl;
    return 0;
}