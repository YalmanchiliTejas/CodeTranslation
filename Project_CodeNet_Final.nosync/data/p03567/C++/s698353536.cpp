#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define _abs(x)((x) < 0 ? (x) * -1 : (x))
#define _max(x, y)(max(0, max((x), (y))))
#define _min(x, y)(max(0, min((x), (y))))

#define pb push_back
#define mp make_pair

static const ll MOD = 1e9 + 7;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //freopen("debug.txt", "w", stderr);

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;

    cin >> s;

    int i, len = s.size() - 1;

    for (i = 0; i < len; i++) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            cout << "Yes" << '\n';

            return 0;
        }
    }

    cout << "No" << '\n';

    return 0;
}
