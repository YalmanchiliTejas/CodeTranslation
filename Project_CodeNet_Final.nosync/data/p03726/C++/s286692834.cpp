/**
 *    author:  [itmo] enot110
 *    created: 06.05.2017 15:11:05       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 1e5 + 10;

vi v[N];
set<int> s[N];
int dead[N];
int cnt[N];
int deg[N];

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n - 1)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        v[x].pb(y);
        v[y].pb(x);
        deg[x]++;
        deg[y]++;
        s[x].insert(y);
        s[y].insert(x);
    }
    if (n == 1) return 0 * printf("First\n");
    forn(i, n) if (sz(v[i]) == 1)
    {
        cnt[v[i][0]]++;
        dead[i] = 1;
        //eprintf("dead %d\n", i);
    }
    set<pi> S;
    forn(i, n) if (!dead[i]) S.insert({-cnt[i], i});

    while (sz(S))
    {
        int x = S.begin()->S;
        S.erase(S.begin());
        if (dead[x]) continue;
        dead[x] = 1;
        //eprintf("x = %d, cnt = %d\n", x, cnt[x]);
        if (cnt[x] > 1) return 0 * printf("First\n");
        for (int y : v[x]) if (!dead[y])
        {
            s[y].erase(x);
            deg[y]--;
            //eprintf("erase %d from %d, deg
            if (deg[y] == 1)
            {
                dead[y] = 1;
                int z = *s[y].begin();
                if (!dead[z])
                {
                    S.erase({-cnt[z], z});
                    cnt[z]++;
                    S.insert({-cnt[z], z});
                }
            }
        }
    }
    printf("Second\n");




        
    


    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
