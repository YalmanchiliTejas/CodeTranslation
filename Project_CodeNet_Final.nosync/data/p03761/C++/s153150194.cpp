#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }

    vector<int> count(n-1, 0);
    string ans = "";
    for (int i = 0; i < s[0].size(); ++i) {
        int tmp = 0;
        for (int j = 1; j < n; ++j) {
            if (count[j] >= s[j].size()) {
                cout << ans << endl;
                return 0;
            }
            while (s[j][count[j]] < s[0][i]) {
                ++count[j];
                if (count[j] >= s[j].size()) {
                    cout << ans << endl;
                    return 0;
                }
            }
            if (s[j][count[j]] == s[0][i]) {
                ++count[j];
                ++tmp;
            }
        }
        if (tmp == n - 1) ans += s[0][i];
    }
    cout << ans << endl;
    return 0;
}
