#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <class T>
bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;

    //min(x,y)までn枚買う
    int n = min(x, y);
    ans += c * n * 2;
    //min(aかbを買う場合, cを買う場合)
    ans += min(a*(x-n) + b*(y-n), c * (x+y-n*2) * 2);
    //aとbのみ買う場合
    ans = min(ans, a*x + b*y);


    cout << ans << endl;

    return 0;
}
