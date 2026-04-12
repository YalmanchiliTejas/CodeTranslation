#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    deque<ll> d;
    rep(i, n) {
        int idx = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (idx == 0) {
            d.push_front(a[i]);
        }
        else {
            d[idx-1] = a[i];
        }
    }
    cout << d.size() << endl;
    return 0;
}
