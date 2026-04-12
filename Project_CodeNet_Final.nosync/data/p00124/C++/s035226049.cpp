#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second > b.second;
    };
    string str;
    int n, w, e, l;
    for (int t = 0; ; t++) {
        scanf("%d", &n);
        if (n == 0) break;
        if (t) cout << endl;
        pair<string, int> countries[n];
        for (int i = 0; i < n; i++) {
            cin >> str >> w >> l >> e;
            countries[i].first = str;
            countries[i].second = w * 3 + e;
        }
        sort(countries, countries+n, cmp);
        for (int i = 0; i < n; i++) {
            cout << countries[i].first << "," << countries[i].second << endl;
        }
    }
    return 0;
}
