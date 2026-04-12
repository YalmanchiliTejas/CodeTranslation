#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int a[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int lef = 0, righ = n + 1;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        multiset < int > Q;
        for (int i = 1; i <= mid; ++i) {
            Q.insert(-1);
        }
        int oks = 1;
        for (int i = 1; i <= n; ++i) {
            auto it = Q.lower_bound(a[i]);
            if (it == Q.begin()) {
                oks = 0;
                break;
            }
            it--;
            Q.erase(it);
            Q.insert(a[i]);
        }
        if (oks) righ = mid;
        else lef = mid;
    }
    cout << righ << '\n';
    return 0;
}

