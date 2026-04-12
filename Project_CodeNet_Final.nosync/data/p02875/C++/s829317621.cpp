#include <bits/stdc++.h>
#define yes { cout << "YES" << endl; exit(0); }
#define no { cout << "NO" << endl; exit(0); }
#define impossible { cout << "Impossible" << endl; exit(0); }

using namespace std;

typedef long long ll;
typedef pair<int,int> Pair;

const int Nmax = 1e7 + 5, Mod = 998244353;

int n;
int doi[Nmax], fact[Nmax], ifact[Nmax];

static int inm(int x, int y)
{
    return (ll) x * y % Mod;
}

void add_to(int &x, int y)
{
    x += y; if(x >= Mod) x -= Mod;
}

void inm_to(int &x, int y)
{
    x = (ll) x * y % Mod;
}

static int comb(int n, int k)
{
    return inm( fact[n], inm(ifact[k], ifact[n-k]) );
}

int power(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1) inm_to(ans, a);
        b >>= 1;
        inm_to(a, a);
    }
    return ans;
}

int main()
{
    //freopen("inputC", "r", stdin);
    // freopen("output", "w", stdout);
    cin.sync_with_stdio(false); cin.tie(0);

    cin >> n;

    int i;
    int ans = 1;
    
    doi[0] = 1; fact[0] = 1; ifact[0] = 1;
    for(i=1; i<=n; ++i) inm_to(ans, 3), doi[i] = inm(doi[i-1], 2), fact[i] = inm(fact[i-1], i);

    ifact[n] = power(fact[n], Mod-2);
    for(i=n-1; i; --i) ifact[i] = inm(ifact[i+1], i+1);

    int wrong = 0;
    for(i=n/2+1; i<=n; ++i)
        add_to( wrong, inm (comb(n, i), doi[n-i] ) );
    
    inm_to(wrong, 2);
    add_to(ans, Mod - wrong);

    cout << ans << '\n';

    return 0;
}

