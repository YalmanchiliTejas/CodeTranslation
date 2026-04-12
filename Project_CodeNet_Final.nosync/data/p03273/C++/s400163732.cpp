#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
const int N = 1e2 + 5;
int f[N], g[N];
char a[N][N];
int main()
{
    ll h, w;
    cin >> h >> w;
    rep(i, h) cin >> a[i];
    rep(i, h) rep(j, w) if (a[i][j] == '#') f[i] = g[j] = 1;
    rep(i, h)
    {
        if (f[i])
        {
            rep(j, w)
            {
                if (g[j])
                {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}