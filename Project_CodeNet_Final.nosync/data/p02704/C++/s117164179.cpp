#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <class T1, class T2>
ostream& operator << (ostream& out, const pair <T1, T2> p)
{
    out << '(' << p.first << ',' << p.second << ')';
    return out;
}

template <class T1, class T2>
istream& operator >> (istream& in, pair<T1, T2> &p)
{
    in >> p.first >> p.second;
    return in;
}

template <class T>
istream& operator >> (istream& in, vector<T> &v)
{
    for (T &x : v)
        in >> x;
    return in;
}

template <class T>
ostream& operator << (ostream& out, const vector<vector<T>> &v)
{
    for (const vector<T> &x : v)
        out << x << '\n';
    return out;
}

template <class T>
ostream& operator << (ostream& out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}

long long gcd (long long a, long long b)
{
    if (b > a)
        swap(a, b);
    return (b ? gcd(b, a % b) : a);
}

using ll   = long long;
using pii  = pair<int, int>;
using pll  = pair<long long, long long>;
using tiii = pair<pair<int, int>, int>;
using vi   = vector<int>;
using vl   = vector<long long>;
using vvi  = vector<vector<int>>;
using vvl  = vector<vector<long long>>;

#define F          first
#define S          second
#define First      first.first
#define Second     first.second
#define Third      second
#define mp         make_pair
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,b,a) for (int i = (b); i > (a); i--)
#define all(x)     x.begin(), x.end()
#define ret(x)     return cout << x, 0;
#define throwex    throw runtime_error ("Found the error.");

const int h = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    #ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.setstate(ios::failbit);
    #endif

    int n;
    cin >> n;
    vector<unsigned long long> s(n), t(n), u(n), v(n);
    cin >> s >> t >> u >> v;
    vector<vector<unsigned long long>> g(n, vector<unsigned long long>(n));
    enum {And, Or};
    rep(i,0,n)
        rep(j,0,n)
        {
            if(s[i] == And and t[j] == And)
                g[i][j] = u[i] | v[j];
            else if(s[i] == Or and t[j] == Or)
                g[i][j] = u[i] & v[j];
            else if(s[i] == And and t[j] == Or)
            {
                if((u[i] | v[j]) != v[j])
                    ret(-1);
                g[i][j] = v[j];
            }
            else if(s[i] == Or and t[j] == And)
            {
                if((u[i] | v[j]) != u[i])
                    ret(-1);
                g[i][j] = u[i];
            }
        }

    rep(_,0,2)
    {
        vvi ss(n, vi(64)), tt(n, vi(64));
        rep(i,0,n)
            rep(j,0,n)
                rep(x,0,64)
                {
                    ss[i][x] += (g[i][j] >> x) & 1;
                    tt[j][x] += (g[i][j] >> x) & 1;
                }

        rep(i,0,n)
        {
            if(s[i] != And)
                continue;
            unsigned long long a = ~0ULL;
            rep(j,0,n)
                a &= g[i][j];
            unsigned long long to_remove = a ^ u[i];
            rep(x,0,64)
            {
                if(!((to_remove >> x) & 1))
                    continue;
                bool y = false;
                rep(j,0,n)
                {
                    if(t[j] != Or)
                        continue;
                    if(((g[i][j] >> x) & 1) and tt[j][x] > 1)
                    {
                        y = true;
                        g[i][j] ^= 1ULL << x;
                        tt[j][x]--;
                        break;
                    }
                }
                if(!y)
                    ret(-1);
            }
        }

        rep(i,0,n)
            rep(j,0,i)
                swap(g[i][j], g[j][i]);
        
        swap(s, t);
        swap(u, v);
    }

    cout << g;
}
