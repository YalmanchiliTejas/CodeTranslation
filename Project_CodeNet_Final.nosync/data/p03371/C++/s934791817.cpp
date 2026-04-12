#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using VVI = vector<vector<int>>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int pa = 0, pb = 0;
    ll price = a * x + b * y;
    ll mini = price;
    for (int i = 0; i < 200000; i += 2) // ミックスピザを何枚注文するか
    {
        if (x > 0)
        {
            x--;
            price -= a;
        }
        if (y > 0)
        {
            y--;
            price -= b;
        }
        price += (c * 2);
        mini = min(mini, price);
    }
    cout << mini << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}