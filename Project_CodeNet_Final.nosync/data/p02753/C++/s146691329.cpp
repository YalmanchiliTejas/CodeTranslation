#include <bits/stdc++.h>

#define debug(s) cout << s << endl
#define debug1(s, t) cout << s << " " << t << endl
#define debug2(s, t, u) cout << s << " " << t << " " << u << endl
#define printvec(v)       \
    for (auto &&i : v)    \
        cout << i << " "; \
    cout << endl

using namespace std;
using i64 = long long;

int main()
{
    string s;
    cin >> s;
    bool flag = (s[0] == s[1]) && (s[1] == s[2]);

    if (!flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}