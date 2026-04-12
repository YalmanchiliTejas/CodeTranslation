#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s, t;
    cin >> n >> s >> t;
    vector<pair<int, int>> path;
    path.emplace_back(0, s);
    cout << "? " << s << ' ' << t << endl;
    int d;
    cin >> d;
    path.emplace_back(d, t);
    for (int i = 1; i <= n; i++) {
        if (i == s || i == t) continue;
        cout << "? " << s << ' ' << i << endl;
        int a;
        cin >> a;
        cout << "? " << i << ' ' << t << endl;
        int b;
        cin >> b;
        if (d == a + b) {
            path.emplace_back(a, i);
        }
    }
    sort(path.begin(), path.end());
    int N = path.size();
    vector<bool> check(N);
    check[0] = true;
    stringstream ans;
    ans << "! " << s;
    int prev = s, prevd = 0;
    while (1) {
        for (int i = 1; i < N; i++) {
            if (check[i] == false) {
                int a = path[i].second;
                cout << "? " << prev << ' ' << a << endl;
                int c;
                cin >> c;
                if (c != path[i].first - prevd) {
                    check[i] = true;
                } else {
                    prev = a;
                    prevd = path[i].first;
                    check[i] = true;
                    ans << ' ' << a;
                    if (a == t) goto finish;
                    break;
                }
            }
        }
    }
    finish:
    cout << ans.str() << endl;
}
