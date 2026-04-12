#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<int>;
using A = array<int, 2>;
using P = pair<int, int>;
constexpr int MOD{1000000000 + 7};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
constexpr array<int, 4> dx{1, 0, -1, 0}, dy{0, 1, 0, -1};
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
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
constexpr int div_roundup(int a, int b)
{
    return (a + b - 1) / b;
}

// vector<vector<int>> vec(n_rows, vector<int>(n_cols, value));

// *****************************************************************************

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 各単調増加部分列の最後の値たち
    multiset<int> c;
    c.insert(a[0]);
    for (int i = 1; i < n; i++)
    {
        // cからa[i]より小さくない最初の値を探す
        auto it = c.lower_bound(a[i]);
        // その値がcの最も小さい値なら，cのすべての値はa[i]より大きい
        // いまある部分列にa[i]を追加できない．部分列を新しく追加する
        if (it == c.begin())
        {
            c.insert(a[i]);
        }
        // その一つ前の部分列の最後にa[i]を追加する
        else
        {
            c.erase(--it);
            c.insert(a[i]);
        }
    }
    // lb(3) 2, 5
    //

    cout << c.size() << endl;
}

// *****************************************************************************

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(0);

    solve();
}
