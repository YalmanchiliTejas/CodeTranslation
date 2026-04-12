#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "yuiophjklnm";
    set<char> set;
    for (char c : a)
        set.insert(c);

    string s;
    while (cin >> s, s != "#") {
        int cur = set.count(s[0]);

        int ans = 0;
        for (char c : s) {
            if (cur != set.count(c)) {
                ans++;
                cur = set.count(c);
            }
        }
        cout << ans << endl;
    }
}