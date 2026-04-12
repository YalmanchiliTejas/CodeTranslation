#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        if (s == "#") break;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string mp[30];
        int h = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '/') {
                h++;
            } else {
                if (s[i] == 'b') {
                    mp[h] += 'b';
                } else {
                    int num = s[i] - '0';
                    while (num--) mp[h] += '.';
                }
            }
        }
        swap(mp[c - 1][d - 1], mp[a - 1][b - 1]);
        string ans = "";
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j < mp[i].size(); j++) {
                if (mp[i][j] == 'b') {
                    ans += 'b';
                } else {
                    int cnt = 0;
                    while (mp[i][j++] == '.') cnt++;
                    ans += (cnt + '0');
                    j -= 2;
                }
            }
            if(i != h) ans += '/';
        }
        cout << ans << endl;
    }
    return 0;
}
