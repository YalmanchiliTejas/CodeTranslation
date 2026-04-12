#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6;
const ll LINF = 1e18;
using namespace std;

#define rep(i, n) for (int(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (int i = (a); i < (b); i++)
#define rrrep(i, a, b) for (int i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl

ll n, cnt, ans, a[ohara], b, c, d, tmp, tmpp, m, h, w, x, y, sum, pos, k;
ld doua;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
bool fl;
struct edge
{
    int to, cost;
};

//-------------------------↓↓↓↓↓↓------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i, n) cin >> a[i];
    while (1)
    {
        ll ma = 0, flags;
        rep(j, n)
        {
            if (ma <= a[j])
            {
                ma = a[j];
                flags = j;
            }
        }
        if (ma <= n - 1)
        {
            break;
        }
        ll herkai;
        tmp = (ma - (n - 1)) / n;
        if ((ma - (n - 1)) % n != 0)
            tmp++;
        herkai = tmp;
        ans += herkai;
        ma -= herkai * n;
        a[flags] = ma;
        rep(j, n)
        {
            if (j == flags)
                continue;
            a[j] += herkai;
        }
    }
    Cout(ans);
    return 0;
}
