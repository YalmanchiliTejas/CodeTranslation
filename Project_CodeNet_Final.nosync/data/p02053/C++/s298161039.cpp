#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<int> x, y;
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == 'B')
            {
                x.push_back(i + j);
                y.push_back(i - j);
            }
        }
    }
    int sz = x.size();
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int ret = max(x[sz - 1] - x[0], y[sz - 1] - y[0]);
    cout << ret << endl;
}

