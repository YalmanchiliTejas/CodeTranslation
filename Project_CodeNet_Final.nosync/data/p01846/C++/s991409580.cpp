#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

void makeboard(string jfen, vector<string> &b)
{
    string line = "";
    for (char c : jfen)
    {
        if (c == 'b')
        {
            line += "b";
        }
        else if (c == '/')
        {
            b.push_back(line);
            line = "";
        }
        else
        {
            rep(i, c - '0')
                line += ".";
        }
    }
    b.push_back(line);
}

string makejfen(vector<string> &board)
{
    string ret = "";
    int h = board.size();
    int w = board[0].size();
    rep(i, h)
    {
        int tmp = 0;
        for (char c : board[i])
        {
            if (c == 'b')
            {
                if (tmp != 0)
                {
                    ret += to_string(tmp);
                }
                ret += "b";
                tmp = 0;
            }
            else
            {
                tmp++;
            }
        }
        if (tmp != 0)
        {
            ret += to_string(tmp);
        }
        if (i != h - 1)
            ret += "/";
    }
    return ret;
}
bool solve()
{
    string jfen;
    cin >> jfen;
    if (jfen == "#")
        return false;
    vector<string> board;
    makeboard(jfen, board);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    board[a][b] = '.';
    board[c][d] = 'b';
    cout << makejfen(board) << endl;
    ;
    return true;
}

int main()
{
    while (solve())
        ;
    return 0;
}
