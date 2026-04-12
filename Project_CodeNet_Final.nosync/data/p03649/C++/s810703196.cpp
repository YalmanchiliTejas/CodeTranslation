#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 55, MAGIC = 50000;
const long long inf = 600000000000000000;

int n;
long long a[max_n], b[max_n], ans;

int get_cnt(long long a[]) {
    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] + 1 >= a[n - 1] - n) {
            ++res;
        }
    }
    return res;
}

int upd(long long cnt, long long x) {
    long long y = x / cnt;
    for (int i = n - 1; i >= n - cnt; --i) {
        long long z = y;
        if (x % cnt >= n - i) {
            ++z;
        }
        b[i] = a[i] - z * n + (x - z);
    }
    for (int i = n - cnt - 1; i >= 0; --i) {
        b[i] = a[i] + x;
    }
    return n - 1 - (x % cnt);
}

bool fail(long long cnt, long long x) {
    long long y = x / cnt;
    x = a[n - 1];
    for (int i = 0; i < n; ++i) {
        x -= y;
        if (x < 0) {
            return true;
        }
    }
    return false;
}

bool proc() {
    pair<long long, int> mx = make_pair(-1, -1);
    for (int i = 0; i < n; ++i) {
        mx = max(mx, make_pair(a[i], i));
    }
    if (mx.first < n) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        if (mx.second == i) {
            a[i] -= n;
        } else {
            ++a[i];
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= 10000000000000000LL) {
            cout << "FAIL" << endl;
            exit(0);
        }
    }
    while (true) {
        sort(a, a + n);
        int cnt = get_cnt(a);
        if (cnt == n) {
            break;
        }
        if (0) {
            cout << "#" << cnt << ": ";
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
            cout << endl;
            cout << endl;
        }
        long long l = 0, r = inf;
        while (r - l > 1) {
            long long mid = (l + r) / 2;
            int pos = upd(cnt, mid);
            if (b[n - cnt - 1] >= b[pos] || fail(cnt, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        upd(cnt, r);
        int f = 0;
        if (get_cnt(b) == n) {
            r = max(0LL, r - MAGIC);
            f = 1;
        }
        //cout << "$" << r << endl << inf << endl;
        ans += r;
        upd(cnt, r);
        for (int i = 0; i < n; ++i) {
            a[i] = b[i];
        }
        if (f == 1) {
            break;
        }
    }
    sort(a, a + n);
    while (get_cnt(a) != n) {
        if (proc()) {
            ++ans;
            sort(a, a + n);
        } else {
            break;
        }
    }
    long long l = -1, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2, mx = 0;
        int pos = upd(n, mid);
        for (int i = 0; i < n; ++i) {
            mx = max(mx, b[i]);
        }
        if (mx < n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    //cout << r << endl;
    if (r >= MAGIC) {
        r -= MAGIC;
    } else {
        r = 0;
    }
    ans += r;
    upd(n, r);
    for (int i = 0; i < n; ++i) {
        a[i] = b[i];
        //cout << a[i] << endl;
    }
    while (proc()) {
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
