#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;

pair<string, int> dp[200005] = {};
int main()
{
    int l;
    string s, t;
    cin >> l;
    cin >> s >> t;
    int x = s.size();
    int y = t.size();
    int ans = 0;
    if (x == y) {
        if (s > t) {
            swap(s, t);
        }
        rep(i, l / s.size()) cout << s;
        cout << endl;
    } else {
        string st = s + t;
        string ts = t + s;


        if (st > ts) {
            swap(s, t);
        }
        x = s.size();
        y = t.size();
        for (int i = 0; i * x <= l; i++) {
            if ((l - i * x) % y == 0) {
                ans = i;
            }
        }
        rep(i, ans)
        {
            cout << s;
        }
        rep(i, (l - x * ans) / y)
        {

            cout << t;
        }
        cout << endl;
    }
}
