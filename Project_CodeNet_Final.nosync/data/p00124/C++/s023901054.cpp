#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n;
    string s;
    int w, l, d;
    bool p = 0;
    while (cin >> n, n)
    {
        if (p)
            cout << endl;
        p = 1;
        multimap<int, string, greater<int>> mp;
        rep(i, n)
        {
            cin >> s >> w >> l >> d;
            mp.insert(make_pair(3 * w + d, s));
        }

        for (auto a : mp)
            cout << a.second << "," << a.first << endl;
    }
    return 0;
}
