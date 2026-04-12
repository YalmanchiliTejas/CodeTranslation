#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define _abs(x)((x) < 0 ? (x) * -1 : (x))
#define _max(x, y)(max(0, max((x), (y))))
#define _min(x, y)(max(0, min((x), (y))))
template<typename T> inline bool __max__(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template<typename T> inline bool __min__(T &x, const T &y) { return x > y ? x = y, 1 : 0; }

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

    long x, y, z;

    cin >> x >> y >> z;

    bool isSpace = true;
    long ans = 0L;

    long i = 0;

    while (i <= x) {
        if (isSpace) {
            i += z;
            isSpace = false;
        } else {
            if (i + y + z <= x) {
                i += y;
                ans++;
                isSpace = true;
            } else {
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
