#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vii;
const int N = 10;
int a[N][N];
int n, m;
int v[N];
ll ans;
int main()
{
    cin >> n >> m;
    FOR(i, 1, n - 1) v[i] = i + 1;
    FOR(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    do
    {
        bool ok = 1;
        if(a[1][v[1]] == 0) ok = 0;
        FOR(i, 1, n - 2)
        {
            if(a[v[i]][v[i + 1]] == 0)
            {
                ok = 0;
                break;
            }
        }
        if(ok) ans++;
    }while(next_permutation(v + 1, v + n));
    cout << ans;
    return 0;
}
