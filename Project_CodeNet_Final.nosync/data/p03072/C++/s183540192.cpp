#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v: a) cin >> v;
    int h = -1, an = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= h) an++;
        h = max(h, a[i]);
    }
    cout << an << endl;
    return 0;
}
