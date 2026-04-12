#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for (int i = (n); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    int h[n];
    rep(i, n) cin >> h[i];

    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        bool flag = 0;
        rep(j, i)
        {
            if (h[j] > h[i])
                flag = 1;
        }
        if (flag == 0)
            cnt++;
    }
    OP(cnt);
    return 0;
}