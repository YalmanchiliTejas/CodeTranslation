#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> as(1);
    {
        int a;
        cin >> a;
        as[0].push_back(a);
    }
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        if (as.back().back() >= a) {
            as.emplace_back(vector<int>({a}));
        } else {
            int sz = as.size();
            int l = -1, r = sz - 1;
            while (l < r - 1) {
                int m = (l + r) / 2;
                if (as[m].back() < a) {
                    r = m;
                } else {
                    l = m;
                }
            }
            as[r].push_back(a);
        }
    }
    cout << as.size() << endl;
}