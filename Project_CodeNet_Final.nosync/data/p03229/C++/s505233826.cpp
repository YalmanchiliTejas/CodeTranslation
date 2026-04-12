#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20)
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

int n, a;

signed main() {
    INCANT;
    cin>>n;
    deque<int> q, d;
    for (int i = 0; i < n; i++) {
        cin>>a;
        q.push_back(a);
    }
    sort(q.begin(), q.end());
    d.push_back(q.back()); q.pop_back();
    int turn = 0;
    while (!q.empty()) {
        if (turn % 2) {
            d.push_front(q.back()); q.pop_back();
            if (q.empty()) break;
            d.push_back(q.back()); q.pop_back();
        } else {
            d.push_front(q.front()); q.pop_front();
            if (q.empty()) break;
            d.push_back(q.front()); q.pop_front();
        }
        turn++;
    }
    int res = 0;
    int mn = INF;
    for (int i = 0; i < n - 1; i++) {
        res += abs(d[i + 1] - d[i]);
        mn = min(mn, abs(d[i + 1] - d[i]));
    }
    res += abs(d[0] - d[n - 1]);
    mn = min(mn, abs(d[0] - d[n - 1]));
    cout<<res - mn<<endl;
}