#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair <int, pair <int, int> > iii;

int dist (pair <int, int> p1, pair <int, int> p2) {
    return min(abs(p1.first - p2.first), abs(p1.second - p2.second));
}

int p[100005];

void init (int n) {
    for (int i = 1; i<=n; i++) {
        p[i] = i;
    }
}

int up (int x) {
    return (p[x] == x ? x : p[x] = up(p[x]));
}

bool isSame(int x, int y) {
    return (up(x) == up(y));
}

void unionSet (int x, int y) {
    if (isSame(x, y)) return;

    p[up(y)] = up(x);
}

signed main(){
    int n;
    scanf("%lld", &n);
    pair <pair <int, int>, int> a[n + 1];

    for (int i = 1; i<=n; i++) {
        int x, y;
        scanf("%lld %lld", &a[i].first.first, &a[i].first.second);
        a[i].second = i;
    }

    init(n + 1);

    sort(a + 1, a + n + 1);

    priority_queue <iii, vector <iii>, greater <iii> > pq;
    for (int i = 2; i<=n; i++) pq.push(make_pair(dist(a[i].first, a[i - 1].first), make_pair(a[i].second, a[i - 1].second)));
    for (int i = 1; i<=n; i++) swap(a[i].first.first, a[i].first.second);

    sort(a + 1, a + n + 1);
    for (int i = 2; i<=n; i++) pq.push(make_pair(dist(a[i].first, a[i - 1].first), make_pair(a[i].second, a[i - 1].second)));

    int cur = n - 1;
    int ans = 0;
    while (cur > 0 && pq.size() > 0) {
        iii u = pq.top(); pq.pop();

        if (isSame(u.second.first, u.second.second)) continue;

        unionSet(u.second.first, u.second.second);
        cur--;
        ans += u.first;
    }

    printf("%lld", ans);
    return 0;
}
