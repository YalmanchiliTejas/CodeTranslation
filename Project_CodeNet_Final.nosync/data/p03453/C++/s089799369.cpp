#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n, m;
long long d[N], f[N];
long long cd[N], cf[N];
vector < pair < int, int > > v[N];

void add(long long &x, long long y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

void djk(int x, long long *d, long long *c)
{
        long long inf = 1e18;
        for(int i = 1; i <= n; i++){
                d[i] = inf;
                c[i] = 0;
        }
        d[x] = 0;
        c[x] = 1;
        set < pair < long long, int > > s;
        s.insert({0, x});
        while(!s.empty()){
                int x = s.begin()->se;
                s.erase(s.begin());
                for(auto y: v[x]){
                        if(d[y.fi] > d[x] + y.se){
                                s.erase({d[y.fi], y.fi});
                                d[y.fi] = d[x] + y.se;
                                c[y.fi] = c[x];
                                s.insert({d[y.fi], y.fi});

                        } else if(d[y.fi] == d[x] + y.se){
                                add(c[y.fi], c[x]);
                        }
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        int s, t;
        cin >> s >> t;
        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back({y, w});
                v[y].push_back({x, w});
        }

        djk(s, d, cd);
        djk(t, f, cf);

        long long need = d[t];
        long long res = cd[t] * cf[s] % mod;
        for(int i = 1; i <= n; i++){
                if(d[i] * 2 == need && f[i] * 2 == need){
                        long long ways = cd[i] * cf[i] % mod;
                        res -= ways * ways % mod;
                }
                for(auto j: v[i]){
                        if(d[i] > d[j.fi] || d[i] + f[j.fi] + j.se != need){
                                continue;
                        }
                        long long L1 = min(d[i], d[j.fi]);
                        long long R1 = max(d[i], d[j.fi]);
                        long long L2 = min(f[i], f[j.fi]);
                        long long R2 = max(f[i], f[j.fi]);
                        if(L1 * 2 < need && need < R1 * 2 && L2 * 2 < need && need < R2 * 2){
                                long long ways = cd[i] * cf[j.fi] % mod;
                                res -= ways * ways % mod;
                        }
                }
        }

        res %= mod;
        res += mod;
        res %= mod;

        cout << res << "\n";
}
