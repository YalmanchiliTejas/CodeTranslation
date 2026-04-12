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
    int N, M, a, b, ans = 0;
    cin >> N >> M;
    auto graph = make_v<int>(N, N);
    fill_v(graph, false);
    rep(i, M)
    {
        cin >> a >> b;
        a--;
        b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    vint per(N);
    rep(i, N)
    {
        per[i] = i;
    }
    do
    {
        bool ok = true;
        rep(i, N - 1)
        {
            if (!graph[per[i]][per[i + 1]])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            ans++;
    } while (next_permutation(++per.begin(), per.end()));
    cout << ans;
    return 0;
}