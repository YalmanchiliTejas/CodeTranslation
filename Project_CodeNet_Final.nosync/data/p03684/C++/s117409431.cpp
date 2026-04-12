#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    vector<pair<int, int>> xV, yV;
    vector<int> c[n];
    int p[n];
    long long ans = 0;

    for (int i = 0; i < n; i++)
        c[i].push_back(i), p[i] = i;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xV.push_back({x, i});
        yV.push_back({y, i});
    }
    sort(xV.begin(), xV.end());
    sort(yV.begin(), yV.end());

    for (int i = 1; i < n; i++) {
        q.push({xV[i].first - xV[i - 1].first, {xV[i - 1].second, xV[i].second}});
        q.push({yV[i].first - yV[i - 1].first, {yV[i - 1].second, yV[i].second}});
    }

    while (true) {
        int cur, a, b;
        cur = q.top().first;
        a = q.top().second.first;
        b = q.top().second.second;
        q.pop();

        if (p[a] != p[b]) {
            if (c[p[a]].size() > c[p[b]].size())
                swap(a, b);

            vector<int> v, empty;
            v = c[p[a]];
            c[p[a]].swap(empty);

            for (int x : v)
                p[x] = p[b], c[p[b]].push_back(x);
            ans += cur;

            if (c[p[b]].size() == n)
                break;
        }
    }
    cout << ans << '\n';
}