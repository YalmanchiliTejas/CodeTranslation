#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }

    string ans;
    for (int c = 0; c < 26; c++) {
        int size = 50;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int l = 0; l < (int)s.at(i).size(); l++) {
                if (s.at(i).at(l) == (char)('a' + c)) cnt++;
            }

            size = min(size, cnt);
        }

        for (int s = 0; s < size; s++) {
            ans += (char)('a' + c);
        }
    }

    cout << ans << endl;
}   