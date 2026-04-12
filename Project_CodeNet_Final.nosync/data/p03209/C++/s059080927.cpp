#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

vector<ll> a(1, 1), p(1, 1); //a：全体の枚数，p；パティの枚数

ll f(ll n, ll x)
{
    if (n == 0)
    {
        if (x <= 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (x <= 1 + a[n - 1])
    {
        return f(n - 1, x - 1);
    }
    else
    {
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
    }
}

int main()
{
    ll n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }
    cout << f(n, x) << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}