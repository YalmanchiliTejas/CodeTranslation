#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()

int n;
vector<pair<int, int>> v;
int mn = 1e9 + 123, mx = -1;

long long calc1() {
    long long red = mx - mn;

    vector< pair<int, int> > blues;
    for (int i = 0; i < n; i++) {
        int from = v[i].second, to = v[i].first;
        blues.push_back({from, to});
    }
    sort(all(blues));

    long long result = 1ll * red * (blues.back().first - blues[0].first);

    long long convertedMin = blues[0].second;
    long long convertedMax = blues[0].second;
    for (int i = 0; i < n; i++) {
        convertedMin = min(convertedMin, 1ll * blues[i].second);
        convertedMax = max(convertedMax, 1ll * blues[i].second);
        long long l = convertedMin;
        long long r = convertedMax;
        if (i + 1 < n) {
            l = min(l, 1ll * blues[i + 1].first);
            r = max(r, 1ll * blues.back().first);
        }
        result = min(result, 1ll * red * (r - l));
    }

    return result;
}

long long f(long long r) {
    long long redFrom = mn, redTo = r;
    long long blueFrom = mx, blueTo = mx;

    for (int i = 0; i < sz(v); i++) {
        long long from = v[i].second, to = v[i].first;
        if (from >= redFrom && from <= redTo) {
            blueFrom = min(blueFrom, to);
        } else {
            blueFrom = min(blueFrom, from);
        }
    }

    return 1ll * (redTo - redFrom) * (blueTo - blueFrom);
}

long long calc2() {
    long long l = mn, r = mx;

    for (int i = 0; i < sz(v); i++) {
        long long from = v[i].second;
        if (from == mn) {
            continue;
        }
        l = max(l, from);
    }

    while (r - l > 5) {
        long long mid1 = l + (r - l) / 3;
        long long mid2 = r - (r - l) / 3;
        if (f(mid1) < f(mid2)) {
            r = mid2;
        } else {
            l = mid1;
        }
    }

    long long result = f(l);
    while (l != r) {
        result = min(result, f(l));
        l++;
    }
    return result;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        if (from > to) {
            swap(from, to);
        }

        mn = min(mn, from);
        mx = max(mx, to);
        v.push_back({to, from});
    }

    sort(all(v));

    // cerr << calc1() << " " << calc2() << endl;
    cout << min(calc1(), calc2()) << endl;

    return 0;
}
