
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
typedef unsigned long long ull;
typedef long long ll;
#define mod 1000000007
#define REP(i, n) for (unsigned long long i = 0; i < (n); i++)
#define FOR(i, a, b) for (unsigned long long i = (a); i <= (b); i++)
#define FORD(i, a, b) for (unsigned long long i = (a); i >= (b); i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define debug(x) cout << #x << '=' << (x) << endl;
#define debugp(x) cout << #x << "= {" << (x.first) << ", " << (x.second) << "}" << endl;
#define debug2(x, y) cout << "{" << #x << ", " << #y << "} = {" << (x) << ", " << (y) << "}" << endl;
#define debugv(v)         \
    cout << #v << " : ";  \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << endl;
#define all(x) x.begin(), x.end()
/*
inline bool EQ(double a, double b)
{
    return fabs(a - b) < 1e-9;
}
const int INF = 1 << 29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int &n, int b) { n |= two(b); }
inline void unset_bit(int &n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n)
{
    int res = 0;
    while (n && ++res)
        n -= n & (-n);
    return res;
}
template <class T>
void chmax(T &a, const T &b) { a = max(a, b); }
template <class T>
void chmin(T &a, const T &b) { a = min(a, b); }

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long int lcm(long long int a, long long int b)
{
    return (a * b) / gcd(a, b);
}

long long int max(long long int a, long long int b)
{
    if (a > b)
        return a;
    return b;
}

long long int power(long long int x, long long int y)
{
    long long int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

long long int powermod(long long int x, long long int y)
{
    long long int res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

long long mulmod(long long a, long long b)
{
    long long res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }

    return res;
}

bool isPrime(long long int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if ((n % i == 0) || (n % (i + 2) == 0))
            return false;
    }
    return true;
}

long double dist(long long int x1, long long int y1, long long int x2, long long int y2)
{
    return (long double)sqrt((long double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
long long int squaredist(long long int x1, long long int y1, long long int x2, long long int y2)
{
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

long long int nCr(long long int n, long long int r)
{
    if (r == 0)
        return 1;
    return (n * nCr(n - 1, r - 1)) / r;
}

long long int countDivisors(long long int n)
{
    long long int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                cnt++;
            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}

unsigned long long int countDivisibles(unsigned long long int A, unsigned long long int B, unsigned long long int M)
{
    if (A % M == 0)
        return (B / M) - (A / M) + 1;

    return (B / M) - (A / M);
}

long long int xorRange(long long int x, long long int y)
{
    if (x % 2 == 0)
    {
        long long int pattern[] = {y, 1, y + 1, 0};
        return pattern[(int)((y - x) % 4)];
    }
    else
    {
        long long int pattern[] = {x, x ^ y, x - 1, (x - 1) ^ y};
        return pattern[(int)((y - x) % 4)];
    }
}

unsigned long long int maxOrRange(unsigned long long int l, unsigned long long int r)
{
    while (l < r)
        l &= (l + 1);
    return (l & r);
}

long long mul(long long a, long long b)
{
    return (a * b) % mod;
}

long long mul(long a, long long b, long long c)
{
    return mul(mul(a, b), c);
}

long long mul(long long a, long long b, long long c, long long d)
{
    return mul(mul(a, b), mul(c, d));
}

long long add(long long a, long long b)
{
    return (a + b) % mod;
}

long long neg(long long a)
{
    return (mod - (a % mod)) % mod;
}

long long sub(long long a, long long b)
{
    return add(a, neg(b));
}

long long minv(long long a)
{
    int b = mod - 2;
    long long ans = 1;
    while (b)
    {
        if (b % 2)
            ans = mul(ans, a);
        a = mul(a, a);
        b /= 2;
    }
    return ans;
}

long long divi(long long a, long long b)
{
    return mul(a, minv(b));
}

bool sortdesc(const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b)
{
    return (std::get<0>(a) > std::get<0>(b));
}

std::vector<long long> fni(1000);
std::vector<long long> nni(1000);
std::vector<long long> fact(1000);

void Inv_Num_Fact_Factorial(long long p, long long N)
{
    fni[0] = fni[1] = nni[0] = nni[1] = fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (i >= 2)
        {
            nni[i] = mul(nni[p % i], (p - p / i));
            fni[i] = mul(nni[i], fni[i - 1]);
        }
        fact[i] = mul(fact[i - 1], i);
    }
}

long long fnCr(long long int N, long long int R)
{
    return mul(fact[N], fni[R], fni[N - R]);
}

bool findParity(ll x)
{
    ll y = x ^ (x >> 1);
    y = y ^ (y >> 2);
    y = y ^ (y >> 4);
    y = y ^ (y >> 8);
    y = y ^ (y >> 16);
    if (y & 1)
        return 1;
    return 0;
}
*/

using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     ll a,b,c;
//     cin >> a >> b >> c;
//     int arr[a];
//     cin >> arr[0];
//     ll ans = 0;
//     FOR(i,1,a-1){
//         cin >> arr[i];
//         ans += min((arr[i]-arr[i-1])*b,c);
//     }
//     cout << ans;

//     return 0;
// }


const int nmax = 8;
bool graph[nmax][nmax];
int dfs(int v, int N, bool visited[nmax])
{
    bool all_visited = true;
    for (int i = 0; i < N; ++i)
    {
        if (visited[i] == false)
            all_visited = false;
    }

    if (all_visited)
    {
        return 1;
    }

    int ret = 0;

    for (int i = 0; i < N; ++i)
    {
        if (graph[v][i] == false)
            continue;
        if (visited[i])
            continue;

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }

    return ret;
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        graph[A - 1][B - 1] = graph[B - 1][A - 1] = true;
    }

    bool visited[nmax];
    for (int i = 0; i < N; ++i)
    {
        visited[i] = false;
    }

    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
    return 0;
}
