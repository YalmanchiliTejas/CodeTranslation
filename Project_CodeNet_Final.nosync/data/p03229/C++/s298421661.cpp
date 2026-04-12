#include <bits/stdc++.h>
using namespace std;

bool isMax(long long a, long long b, long long c, long long d) {
    if (a >= b && a >= c && a >= d) {
        return true;
    }
    return false;
}

int main(void) {
    int n;
    vector<long long> a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    long long front, rear, ans = 0;
    front = rear = a[0];
    int is = 1, ie = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        long long ss, se, es, ee;
        ss = abs(front - a[is]);
        se = abs(front - a[ie]);
        es = abs(rear - a[is]);
        ee = abs(rear - a[ie]);
        if (isMax(ss, se, es, ee)) {
            ans += ss;
            front = a[is];
            ++is;
        } else if (isMax(se, ss, es, ee)) {
            ans += se;
            front = a[ie];
            --ie;
        } else if (isMax(es, ss, se, ee)) {
            ans += es;
            rear = a[is];
            ++is;
        } else {
            ans += ee;
            rear = a[ie];
            --ie;
        }
    }
    printf("%lld\n", ans);
}
