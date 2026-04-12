#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> s(n);
    string ans;

    for (int i = 0; i < n; ++i) cin >> s[i];

    string alp = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < alp.size(); ++i) {
        int m = 51;
        for (int j = 0; j < n; ++j) {
            int t = count(s[j].begin(), s[j].end(), alp[i]);
            if (m > t) m = t;
        }
        for (int j = 0; j < m; ++j) ans.push_back(alp[i]);
    }

    cout << ans << endl;
}