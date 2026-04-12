#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, AC;
    char c;
    vector<pii> v;
    while (cin >> n >> c >> AC, (n | AC)) {
        v.push_back(pii(-AC, n));
    }
    
    sort(v.begin(), v.end());
    while (cin >> n) {
        int cnt = 1;
        for (int i = 0; i < (int)v.size(); i++) {
            if (i > 0 && v[i].first != v[i-1].first) {
                cnt++;
            }
            if (v[i].second == n) break;
        }
        cout << cnt << endl;
    }
    return 0;
}