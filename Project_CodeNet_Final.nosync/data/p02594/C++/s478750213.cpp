#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP1(i, n) for (int i = 1; i < n + 1; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
#define SZ(x) ((int)(x).size())
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using namespace std;
typedef long long ll;
using p = pair<int, int>;
using P = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using Graph = VV;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    if (x >= 30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
