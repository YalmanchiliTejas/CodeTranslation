#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> getAxis(vector<vector<int>> v, int axis) {
    vector<int> ans(v.size());
    for (int i = 0; i < v.size(); ++i) ans[i] = v[i][axis];
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cnt(n, vector<int>(26, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            cnt[i][c - 'a']++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        vector<int> v = getAxis(cnt, i);
        for (int j = 0; j < *min_element(v.begin(), v.end()); ++j) {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;
}
