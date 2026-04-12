# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
# define fi cin
# define fo cout
# define x first
# define y second
# define ll long long
# define IOS ios_base :: sync_with_stdio(0);cin.tie(0)
# define p(v) cerr << #v << " = " << v << '\n'
# define p2(v) cerr << #v << " = " << (complex < int > (v.x,v.y)) << '\n'
# define vi vector < int >
# define vll vector < ll >
# define pii pair < int , int >
# define mp make_pair
# define int ll
int32_t main(void)
{
    #ifdef CF
    freopen("input","r",stdin);
    #endif // CF
    srand(time(0));
    fo << fixed << setprecision(7);
    cerr << fixed << setprecision(7);
    static int p[1 << 20];
    int n,m;
    fi>>n>>m;
    static char s[55][55];
    for (int i = 1;i <= n;++i)
        fi>>(s[i] + 1);
    int A = -1,B = -1;
    for (int i = 1;A == -1 && i <= n;++i)
        for (int j = 1;A == -1 && j <= m;++j)
            if (s[i][j] == '#')
            {
                A = i;B = j;
            }
    if (A == -1)
        return puts("Impossible") * 0;
    while (A != n || B != m)
    {
        s[A][B] = '.';
        if (s[A + 1][B] != '#' && s[A][B + 1] != '#')
            return puts("Impossible") * 0;
        if (s[A + 1][B] == '#')
            ++A;
        else
            ++B;
    }
    s[A][B] = '.';
    for (int i = 1;i <= n;++i)
        for (int j = 1;j <= m;++j)
            if (s[i][j] == '#')
                return puts("Impossible") * 0;
    return puts("Possible") * 0;
    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}