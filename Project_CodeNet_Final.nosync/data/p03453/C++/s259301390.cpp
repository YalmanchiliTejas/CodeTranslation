

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
#include <bitset>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 100007;
const int MAXX = 1000000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

bool U[MAX];
vector<PII> G[MAX];

int n , m;

vector<pair<Int, Int> > dijkstra(int s)
{
    vector<pair<Int, Int> > d(n , MP(1LL * INF * INF , 0));
    d[s] = MP(0,1);
    set<pair<Int, int> > S;
    S.insert(MP(0, s));
    
    while (!S.empty())
    {
        int v = S.begin()->second;
        S.erase(S.begin());
        
        FOR(i,0,SZ(G[v]))
        {
            int to = G[v][i].first;
            int len = G[v][i].second;
            if (d[to].first > d[v].first + len)
            {
                S.erase(MP(d[to].first , to));
                d[to].first = d[v].first + len;
                S.insert(MP(d[to].first , to));
                d[to].second = 0;
            }
            if (d[to].first == d[v].first + len)
            {
                d[to].second += d[v].second;
                d[to].second %= MOD;
            }
        }
        
    }
    return d;
    
}

Int cnt[MAX];




int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);
    
    cin >> n >> m;
    
    int s , t;
    cin >> s >> t;
    --s;--t;
    
    FOR(i,0,m)
    {
        int a , b , d;
        scanf("%d%d%d" , &a , &b , &d);
        --a;--b;
        G[a].push_back(MP(b , d * 2));
        G[b].push_back(MP(a , d * 2));
    }
    
    
    
    vector<pair<Int,Int> > d1 = dijkstra(s);
    vector<pair<Int,Int> > d2 = dijkstra(t);
    
    Int d = d1[t].first;
    if (d >= 1LL * INF * INF)
    {
        cout << 0 << endl;
        return 0;
    }
    //cout << d << endl;
    Int res = d1[t].second * d1[t].second % MOD;
    //cout << res << endl;
    
    FOR(i,0,n)
    {
        if (d1[i].first == d / 2 && d2[i].first == d / 2)
        {
            Int val = d1[i].second * d2[i].second % MOD;
            res = (res - val * val % MOD + MOD) % MOD;
        }
    }
    
    FOR(v,0,n)
    {
        FOR(i,0,SZ(G[v]))
        {
            int to = G[v][i].first;
            int len = G[v][i].second;
            if (d1[v].first + len + d2[to].first == d && d1[v].first < d / 2 && d2[to].first < d / 2)
            {
                Int val = d1[v].second * d2[to].second % MOD;
                res = (res - val * val % MOD + MOD) % MOD;
            }
        }
    }
    
    
    cout << res << endl;
    
    return 0;
}











