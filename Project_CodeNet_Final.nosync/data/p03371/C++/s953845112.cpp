#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes                \
    cout << "Yes" << endl; \
    return 0;
#define No                \
    cout << "No" << endl; \
    return 0;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template <typename T>
void print(const T &v);

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int mini = INF;
    for (int z = 0; z <= max(X, Y) * 2; z += 2)
    {
        int x_price = (X - (z / 2)) * A;
        int y_price = (Y - (z / 2)) * B;
        if (x_price < 0)
            x_price = 0;
        if (y_price < 0)
            y_price = 0;
        int total = x_price + y_price + (z * C);
        mini = min(mini, total);
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
