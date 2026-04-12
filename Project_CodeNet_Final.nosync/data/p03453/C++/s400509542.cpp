#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define rand_int abs((rand() << 15) | rand())
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const ll MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 2 * 1e5 + 1;
const int MAX_M = 2001;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 19;
const int km = (1 << 18);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

ll dist[MAX_N], way[MAX_N], dp[MAX_N];
int n, m, s, f;
bool used[MAX_N];
vector<vector<pair<int, ll> > > v(MAX_N);
vector<tuple<int, int, ll> > r;
vector<int> topsort;

void dfs(int p)
{
    used[p] = true;
    for (pair<int, ll> t : v[p])
        if (dist[t.first] == dist[p] + t.second)
            if (!used[t.first])
                dfs(t.first);
    topsort.push_back(p);
}

int main()
{   /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    memset(used, 0, sizeof(used));
    cin >> n >> m >> s >> f;
    s--, f--;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        ll d;
        cin >> s >> f >> d;
        s--, f--;
        d *= 2;
        v[s].push_back(make_pair(f, d));
        v[f].push_back(make_pair(s, d));
        r.push_back(make_tuple(s, f, d));
        r.push_back(make_tuple(f, s, d));
    }
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[s] = 0;
    set<pair<ll, int> > q;
    for (int i = 0; i < n; i++)
        q.insert(make_pair(dist[i], i));
    while (!q.empty())
    {
        int p = q.begin()->second;
        q.erase(q.begin());
        for (pair<int, ll> t : v[p])
        {
            if (dist[t.first] > dist[p] + t.second)
            {
                q.erase(make_pair(dist[t.first], t.first));
                dist[t.first] = dist[p] + t.second;
                q.insert(make_pair(dist[t.first], t.first));
            }
        }
    }
    dfs(s);
    reverse(topsort.begin(), topsort.end());
    if (topsort.size() != n) exit(239);
    way[s] = 1;
    for (int i = 1; i < n; i++)
    {
        int x = topsort[i];
        way[x] = 0;
        for (pair<int, ll> t : v[x])
            if (dist[t.first] == dist[x] - t.second)
                way[x] = (way[x] + way[t.first]) % MOD;
    }
    ll ans = (way[f] * way[f]) % MOD;
    ll tim = (dist[f] / 2LL);
    for (int i = n - 1; i >= 0; i--)
    {
        int x = topsort[i];
        if (x == f)
        {
            dp[x] = 1;
            continue;
        }
        dp[x] = 0;
        for (pair<int, ll> t : v[x])
            if (dist[t.first] == dist[x] + t.second)
                dp[x] = (dp[x] + dp[t.first]) % MOD;
    }
    for (int i = 0; i < n; i++)
        if (dist[i] == tim)
        {
            ans = (ans - ((way[i] * dp[i]) % MOD) * ((way[i] * dp[i]) % MOD)) % MOD;
            if (ans < 0) ans += MOD;
        }
    for (tuple<int, int, ll> t : r)
        if (dist[get<1>(t)] == dist[get<0>(t)] + get<2>(t))
        {
            ll lg = dist[get<0>(t)];
            ll rg = lg + get<2>(t);
            if (lg < tim && tim < rg)
            {
                ans = (ans - ((way[get<0>(t)] * dp[get<1>(t)]) % MOD) * ((way[get<0>(t)] * dp[get<1>(t)]) % MOD)) % MOD;
                if (ans < 0) ans += MOD;
            }
        }
    cout << ans;
    return 0;
}
