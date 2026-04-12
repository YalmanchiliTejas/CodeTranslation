#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &ai : a) cin >> ai;
    sort(a.begin(), a.end());

    deque<ll> order;
    int l = 0, r = n - 1;
    order.push_front(a[l++]);
    while (l <= r) {
        if (l <= r) order.push_front(a[r--]);
        if (l <= r) order.push_back(a[r--]);
        if (l <= r) order.push_front(a[l++]);
        if (l <= r) order.push_back(a[l++]);
    }

    ll sum1 = 0;
    for (auto it = order.begin(); it != order.end(); ++it) {
        if (next(it) != order.end()) {
            sum1 += abs(*next(it) - *it);
        }
    }

    l = 0, r = n - 1;
    order.clear();
    order.push_front(a[r--]);
    while (l <= r) {
        if (l <= r) order.push_front(a[l++]);
        if (l <= r) order.push_back(a[l++]);
        if (l <= r) order.push_front(a[r--]);
        if (l <= r) order.push_back(a[r--]);
    }
    ll sum2 = 0;
    for (auto it = order.begin(); it != order.end(); ++it) {
        if (next(it) != order.end()) {
            sum2 += abs(*next(it) - *it);
        }
    }

    cout << max(sum1, sum2) << endl;

    return 0;
}
