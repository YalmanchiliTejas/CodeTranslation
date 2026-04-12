#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define Repr(i, n, a) for (int i = (n); i >= (a); i--)
#define rep(i, n) Rep(i, 0, n)
#define repr(i, n) Repr(i, n, 0)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    while (1)
    {
        cin >> S;
        if (S == "#")
            break;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int field[20][20] = {};
        vector<string> s;
        string t = "";
        rep(i, S.size())
        {
            if (S[i] == '/')
                s.push_back(t), t = "";
            else
                t += S[i];
        }
        s.push_back(t);
        int H = s.size(), W;
        rep(i, s.size())
        {
            string ss = s[i];
            int pos = 0;
            rep(j, ss.size())
            {
                if ('0' <= ss[j] && ss[j] <= '9')
                    pos += ss[j] - '0';
                else
                    field[i][pos++] = 1;
            }
            W = pos;
        }
        field[a][b] = 0;
        field[c][d] = 1;
        string ans = "";
        // rep(i, H)
        // {
        //     rep(j, W)
        //     {
        //         cout << field[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        rep(i, H)
        {
            string tmp = "";
            int cnt = 0;
            rep(j, W)
            {
                if (field[i][j])
                {
                    if (cnt != 0)
                        tmp += '0' + cnt;
                    tmp += 'b';
                    cnt = 0;
                }
                else
                    cnt++;
            }
            if (cnt != 0)
                tmp += '0' + cnt;
            if (i == 0)
                ans += tmp;
            else
                ans += '/' + tmp;
        }
        cout << ans << endl;
    }
}
