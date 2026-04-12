#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define REVERSE(c) (char)(c == 'S' ? 'W' : 'S')
#define NEXT(a, b, c) (char)(a == 'S' ? (b == 'o' ? c : REVERSE(c)) : (b == 'o' ? REVERSE(c) : c))

int main() {
        int n;
        string s, ans;
        bool flag;
        string pre[4] = {"SS", "SW", "WS", "WW"};
        cin >> n >> s;

        for (int i = 0; i < 4; i++) {
                ans = pre[i];
                for (int j = 1; j < n-1; j++) {
                        ans += NEXT(ans[j], s[j], ans[j-1]);
                }
                flag = true;
                for (int j = 0; j < n; j++) {
                        int next = (j + n + 1) % n;
                        int prev = (j + n - 1) % n;
                        if (ans[j] == 'S') {
                                if (s[j] == 'o') {
                                        if (ans[prev] != ans[next])
                                                flag = false;
                                } else {
                                        if (ans[prev] == ans[next])
                                                flag = false;
                                }
                        } else {
                                if (s[j] == 'o') {
                                        if (ans[prev] == ans[next])
                                                flag = false;
                                } else {
                                        if (ans[prev] != ans[next])
                                                flag = false;
                                }
                        }
                }
                if (flag == true)
                        break;
        }
        if (flag == true)
                cout << ans << endl;
        else
                cout << -1 << endl;
        return 0;
}