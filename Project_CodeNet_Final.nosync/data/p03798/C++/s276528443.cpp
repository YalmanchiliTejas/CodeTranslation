#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define REVERSE(c) (char)(c == 'S' ? 'W' : 'S')
#define NEXT(a, b, c) (char)(a == 'S' ? (b == 'o' ? c : REVERSE(c)) \
                                      : (b == 'o' ? REVERSE(c) : c))
#define CHECK(a, b, c, d) (a == 'S' ? (b == 'o' ? c == d : c != d) \
                                    : (b == 'o' ? c != d : c == d))

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
                        if (CHECK(ans[j], s[j], ans[prev], ans[next]) == 0) {
                                flag = false;
                                break;
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
