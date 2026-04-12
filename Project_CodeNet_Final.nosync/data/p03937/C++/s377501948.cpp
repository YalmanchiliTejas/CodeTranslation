#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
    int H, W;
    cin >> H >> W;
    auto A = make_v<char>(W, H);
    rep(y, H)
    {
        rep(x, W)
        {
            cin >> A[x][y];
        }
    }
    pair<int, int> pos = {0, 0};
    A[0][0] = '.';
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    while (pos != pair<int, int>{W - 1, H - 1})
    {
        int x = pos.first, y = pos.second;
        set<int> ok;
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx < W and newx >= 0 and newy < H and newy >= 0 and A[newx][newy] == '#')
            {
                if (i == 0 or i == 1)
                {
                    ok.insert(i);
                }
                else
                {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
        if (ok.size() != 1)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        else
        {
            int idx = *ok.begin();
            pos = {x + dx[idx], y + dy[idx]};
            A[pos.first][pos.second] = '.';
        }
    }
    rep(x,W)
    {
        rep(y,H)
        {
            if(A[x][y]=='#')
            {
            cout << "Impossible" << endl;
            return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}