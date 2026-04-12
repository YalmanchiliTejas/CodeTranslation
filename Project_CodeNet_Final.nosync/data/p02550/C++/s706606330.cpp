#include <bits/stdc++.h>
using namespace std;

long long n;
int x, m;

int next(int a) {
    return (long long) a * a % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> m;
    vector<int> a;
    vector<bool> used(m, 0);
    int cur = x;
    for (; !used[cur]; cur = next(cur)) {
        used[cur] = 1;
        a.push_back(cur);
    }
    vector<int> preperiod;
    int from = 0;
    while (a[from] != cur) {
        preperiod.push_back(a[from]);
        from++;
    }
    vector<int> period;
    for (int i = from; i < a.size(); i++)
        period.push_back(a[i]);
    long long ans = 0;
    int min_ = min<long long>(n, preperiod.size());
    n -= min_;
    for (int i = 0; i < min_; i++)
        ans += preperiod[i];
    long long full = n / period.size();
    for (int x : period)
        ans += full * x;
    n %= period.size();
    for (int i = 0; i < n; i++)
        ans += period[i];
    cout << ans;
    return 0;
}
