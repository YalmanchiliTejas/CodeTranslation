#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define pii pair<int, int>
#define vi vector<int>

using namespace std;
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& p)
{
    return o << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& vc)
{
    o << "sz = " << vc.size() << endl
      << "[";
    for (const T& v : vc)
        o << v << ",";
    o << "]";
    return o;
}
using ll = long long;
constexpr ll MOD = 1000000007;

constexpr int MAX = 200000;

int node[MAX];
bool check[MAX];
vector<int> edge[MAX];
int tree[MAX];

int dfs(const int s)
{
    check[s] = true;
    int b = 0;
    for (const int to : edge[s]) {
        if (not check[to]) {
            const int col = dfs(to);
            if (col == -1) {
                b++;
            }
            if (col == -100) {
                return -100;
            }
            if (b > 1) {
                return -100;
            }
        }
    }
    if (b == 0) {
        return -1;
    } else if (b == 1) {
        return 1;
    }
}

int main()
{
    int N, M;
    cin >> N;
    M = N - 1;

    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        node[a]++;
        node[b]++;
        edge[a].pb(b);
        edge[b].pb(a);
    }

    if (N % 2 == 1) {
        cout << "First" << endl;
        return 0;
    }

    if (dfs(0) != -100) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }

    return 0;
}
