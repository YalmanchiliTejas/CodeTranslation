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
        cerr << v[i] << " \n"[i == sz - 1];
    }
}

int n;
vector<int> p(200);
vector<int> ret;

void pswap()
{
    ret.push_back(n - 1);
    //cout << n - 1 << endl;
    swap(p[0], p[n - 1]);
}

void prot()
{
    ret.push_back(1);
    //cout << 1 << endl;
    int tmp = p[0];
    for (int i = 0; i < n - 1; i++)
    {
        p[i] = p[i + 1];
    }
    p[n - 1] = tmp;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        // i を i+1 の左に持ってくる
        int index0 = -1, index1 = -1;
        for (int j = 0; j < n; j++)
        {
            if (p[j] == i)
            {
                index0 = j;
            }
            if (p[j] == i + 1)
            {
                index1 = j;
            }
        }
        if ((index0 + 1) % n == index1)
        {
            continue;
        }
        while (p[n - 1] != i)
        {
            prot();
        }
        // printv(p);
        pswap();
        while (p[0] != i || p[1] != i + 1)
        {
            prot();
            pswap();
        }
    }
    while (p[0] != 0)
    {
        prot();
    }
    cout << ret.size() << endl;
    for (auto v : ret)
    {
        cout << v << endl;
    }
    // printv(p);
    return 0;
}
