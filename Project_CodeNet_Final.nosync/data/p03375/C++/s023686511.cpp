#include <bits/stdc++.h>

using namespace std;

const int Nmax = 3005;
typedef long long ll;

int n, Mod, comb[Nmax][Nmax], s[Nmax][Nmax], i, j, nr, ans, pw[Nmax*Nmax], pw_pw[Nmax];

int add(int x, int y) { x+=y; return (x<Mod ? x : x-Mod); }
void add_to(int &x, int y) { x+=y; if(x>=Mod) x -= Mod; }
int inm(int x, int y) { return (ll) x*y%Mod; }

int power(int x, int y, int Mod)
{
    int ans = 1;
    while(y)
    {
        if(y&1) ans = (ll)ans*x%Mod;
        x= (ll)x*x%Mod; y >>= 1;
    }
    return ans;
}

int ways(int k)
{
    int i, ans = 0;
    for(i=0; i<=k; ++i)
        add_to( ans, inm( s[k][i], pw[(n-k) * i] ) );

    ans = inm(ans, pw_pw[n-k]);
    return ans;
}

int main()
{
 //   freopen("input", "r", stdin);
 //   freopen("output", "w", stdout);
    cin.sync_with_stdio(false);

    cin >> n >> Mod;

    for(i=0; i<=n; ++i) pw_pw[i] = power(2, power(2, i, Mod-1), Mod);

    pw[0] = 1;
    for(i=1; i<=n*n; ++i) pw[i] = inm(2, pw[i-1]);

    comb[0][0] = 1;
    for(i=1; i<=n; ++i)
        for(j=0; j<=i; ++j)
            comb[i][j] = add(comb[i-1][j], (j ? comb[i-1][j-1] : 0));

    /// modified stirling: every number belongs to at most one subset

    for(i=0; i<=n; ++i)
    {
        s[i][0] = 1;
        for(j=1; j<=i; ++j)
            s[i][j] = add( s[i-1][j-1], inm(j+1, s[i-1][j]) );
    }

    for(i=0; i<=n; ++i) /// at most once
    {
        nr = inm(comb[n][i], ways(i));
        if(i&1) add_to(ans, Mod-nr);
            else add_to(ans, nr);
    }

    cout << ans << '\n';
    return 0;
}

