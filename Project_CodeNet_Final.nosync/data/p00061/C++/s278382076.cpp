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
    vector<pair<int, int>> v(101);
    char c;
    int i = 0;
    while (cin >> v[i].second >> c >> v[i].first, v[i].second)
        i++;

    sort(ALL(v), greater<pair<int, int>>());

    int a[101], rank = 1;
    a[v[0].second] = 1;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first != v[i - 1].first)
        {
            rank += 1;
        }
        a[v[i].second] = rank;
    }

    int n;
    while (cin >> n)
        OP(a[n]);

    return 0;
}
