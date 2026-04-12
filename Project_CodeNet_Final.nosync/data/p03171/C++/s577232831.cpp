#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define int long long
using namespace std;

#define fin(i,n) for (int i = 0; i < n; i++)
#define fin2(i,a,b) for (int i = a; i < b; i++)
#define ford(i,n) for (int i = n-1; i >= 0; i--)
#define ford2(i,a,b) for (int i = a-1; i >= b; i--)
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define mod 1000000007
#define PI 3.1415926535897932384626
#define EXP1 2.718281828459045
#define BIG 1000000000000000000

#define sl(n) scanf("%lld", &n)
#define sll(n,m) scanf("%lld %lld", &n, &m)
#define slll(n,m,k) scanf("%lld %lld %lld", &n, &m, &k)
#define sllll(n,m,k,o) scanf("%lld %lld %lld %lld", &n, &m, &k, &o)
#define sd(n) scanf("%lf", &n)
#define sdd(n,m) scanf("%lf %lf", &n, &m)
#define sddd(n,m,k) scanf("%lf %lf %lf", &n, &m, &k)
#define sc(c) scanf(" %c", &c)
#define ss(s) scanf("%s", s)
#define sal(t,n) fin(iz,n) { scanf("%lld", &t[iz]); }
#define sad(t,n) fin(iz,n) { scanf("%lf", &t[iz]); }
#define gl(t) scanf(" %[^\n]", t);

#define pc(n) printf("%c\n", n)
#define ps(s) printf("%s\n", s)
#define pss(s) printf("%s\n", s.c_str())
#define pl(n) printf("%lld\n", n)
#define pll(n,m) printf("%lld %lld\n", n, m)
#define plll(n,m,k) printf("%lld %lld %lld\n", n, m, k)
#define pd(n) printf("%lf\n", n)
#define pdd(n,m) printf("%lf %lf\n", n, m)
#define pal(t,n) fin(rz,n) { printf("%lld ", t[rz]); } printf("\n")
#define pad(t,n) fin(rz,n) { printf("%lf ", t[rz]); } printf("\n")

#define chmin(x, v) x = min(x, v)
#define chmax(x, v) x = max(x, v)
 
#define OK ps("OK")
#define OK1 ps("OK1")
#define OK2 ps("OK2")

#define ll int
#define vl vector<ll>
#define vvl vector<vl>
#define vvvl vector<vvl>

#define dll pair<ll, ll>
#define vdll vector<dll>
#define vvdll vector<vdll>

#define vb vector<bool>
#define vvb vector<vb>
#define vd vector<double>
#define vvd vector<vd>
#define vc vector<char>
#define vvc vector<vc>

#define all(v) v.begin(), v.end()
#define vlen(v) (int)(v.size())
#define pb push_back
#define fi first
#define se second

const int bm = 3005;
int a[bm];
int dp[2][bm][bm];

int gdp(int j, int g, int d)
{
    if (dp[max(0LL,j)][g][d] == BIG) {
        if (g == d) dp[max(0LL,j)][g][d] = j*a[g];
        else {
            int r1 = gdp(-j, g+1, d) + j*a[g];
            int r2 = gdp(-j, g, d-1) + j*a[d];
            dp[max(0LL,j)][g][d] = j*max(j*r1, j*r2);
        }
    }
    return dp[max(0LL,j)][g][d];
}

signed main()
{
    int n;
    sl(n);
    sal(a, n);
    fill_n(&dp[0][0][0], 2*bm*bm, BIG);
    pl(gdp(1, 0, n-1));
}