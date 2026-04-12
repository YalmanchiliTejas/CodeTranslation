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
    cin >> n;
    string s[n];
    vector<int> maxv(26, 100);
    rep(i, n)
    {
        cin >> s[i];
        rep(j, 26)
        {
            int m = count(ALL(s[i]), (char)('a' + j));
            maxv[j] = min(maxv[j], m);
        }
    }
    string ans = "";
    rep(i, 26)
    {
        if (maxv[i] == 100)
            continue;
        rep(j, maxv[i])
        {
            ans += (char)('a' + i);
        }
    }

    OP(ans);

    return 0;
}