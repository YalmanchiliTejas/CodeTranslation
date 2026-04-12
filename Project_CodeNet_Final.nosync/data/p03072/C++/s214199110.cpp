#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long   ll;
typedef double      db;
typedef long double ldb;

typedef pair<int, int> pii;
typedef pair<ll,  ll>  pll;
typedef pair<ll,  db>  pdd;
typedef pair<ldb, ldb> pldd;
typedef pair<int, ll>  pil;
typedef pair<ll, int>  pli;

typedef vector<int>    vi;
typedef vector<ll>     vl;
typedef vector<char>   vc;
typedef vector<string> vs;
typedef vector<db>     vdb;
typedef vector<ldb>    vldb;
typedef vector<pii>    vpii;
typedef vector<pll>    vpll;
typedef vector<pdd>    vpdd;
typedef vector<pldd>   vpldd;
typedef vector<pil>    vpil;
typedef vector<pli>    vpli;

template<typename T>
void   print(T begin, T end, char = ' ', string msg = "", char = '\n');
template<typename It, typename T>
void   in(It, int, T (*)());

int    si    ();
ll     sl    ();
string ss    (int);
char   sc    ();
float  sf    ();
db     sd    ();
ldb    sld   ();

void   pi    (int, char = '\n');
void   pl    (ll, char = '\n');
void   pf    (float, char = '\n');
void   pc    (char, char = '\n');
void   pdb   (db, char = '\n');
void   pldb  (ldb, char = '\n');
void   ps    (string, char = '\n');

template<typename T>
void   pv    (vector<T> v, char = ' ', char = '\n');

ll russian(ll, ll, ll);
ll fastpow(ll, ll, ll);
ll slowpow(ll, ll, ll);
ll _gcd(ll, ll);
ll _lcm(ll, ll);
ll extgcd(ll, ll, ll&, ll&);
ll _inv(ll, ll);

const int INF  = 1e9;
const ll  LINF = 1e18;

int main()
{
    int n = si();   
    int H[n];

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        H[i] = si();
        bool good = true;
        for (int j = 0; j < i; ++j)
            if (H[j] > H[i])
                good = false;

        if (good)
            ++res;
    }

    pi(res);

    return 0;
}


template<typename T>
string get_token_pointer()
{
    if (is_same<T, int*>::value)
        return "%d";
    if (is_same<T, ll*>::value)
        return "%lld";
    if (is_same<T, char*>::value)
        return "%c";
    if (is_same<T, db*>::value)
        return "%.8lf";
    if (is_same<T, ldb*>::value)
        return "%.10Lf";
    if (is_same<T, float*>::value)
        return "%.6f";
    return "%d";
}

template<typename T>
string get_token()
{
    if (is_same<T, int>::value)
        return "%d";
    if (is_same<T, ll>::value)
        return "%lld";
    if (is_same<T, char>::value)
        return "%c";
    if (is_same<T, db>::value)
        return "%.8lf";
    if (is_same<T, ldb>::value)
        return "%.10Lf";
    if (is_same<T, float>::value)
        return "%.6f";
    return "%d";
}

template<typename It, typename T>
void in(It begin, int nn, T (*get)())
{
    while (nn--)
        *begin++ = get();
}

template <typename T>
T scanf_t(string s)
{
    T a;
    scanf(s.c_str(), &a);
    return a;
}

template <typename T>
void printf_t(T a, string s, char end_l)
{
    s.push_back(end_l);
    printf(s.c_str(), a);
}

// stworzone do tablic tylko
template <typename T>
void print(T begin, T end, char sep, string msg, char end_l)
{
    if (msg != "")
    {
        printf(msg.c_str());
        printf("\n");
    }
    string s = get_token_pointer<T>();
    s.push_back(sep);
    while (begin + 1 != end)
    {
        printf(s.c_str(), *begin);
        begin++;
    }
    if (begin != end)
    {
        s.back() = end_l;
        printf(s.c_str(), *begin);
    }
}

int   si   ()  { return scanf_t<int>("%d");   }
ll    sl   ()  { return scanf_t<ll>("%lld");  }
float sf   ()  { return scanf_t<float>("%.6f"); }
char  sc   ()  { return scanf_t<char>(" %c"); }
db    sdb  ()  { return scanf_t<db>("%.8lf");    }
ldb   sldb ()  { return scanf_t<ldb>("%.10Lf");  }

void pi   (int a,   char end_l)  { printf_t<int>(a, "%d", end_l);   }
void pl   (ll a,    char end_l)  { printf_t<ll>(a, "%lld", end_l);  }
void pf   (float a, char end_l)  { printf_t<float>(a, "%.6f", end_l); }
void pc   (char a,  char end_l)  { printf_t<char>(a, "%c", end_l);  }
void pdb  (db a,    char end_l)  { printf_t<db>(a, "%.8lf", end_l);   }
void pldb (ldb a,   char end_l)  { printf_t<ldb>(a, "%.10Lf", end_l);  }

void ps(string a, char end_l)
{
    string s = "%s";
    s.push_back(end_l);
    printf(s.c_str(), a.c_str());
}

template<typename T>
void pv (vector<T> v, char sep, char end_l)
{
    string s = get_token<T>();
    for (size_t i = 0; i < v.size() - 1; ++i)
        printf_t<T>(v[i], s, sep);
    if (!v.empty())
        printf_t<T>(v.back(), s, end_l);
}

string ss(int NN)
{
    char T[NN + 7];
    scanf("%s", T);
    return (string)T;
}

ll fastpow(ll a, ll k, ll m)
{
    ll r = 1LL;
    while (k)
    {
        if (k & 1LL)
            r = (r * a) % m;
        a = (a * a) % m;
        k >>= 1LL;
    }
    return r;
}

ll slowpow(ll a, ll k, ll m)
{
    ll r = 1LL;
    while (k)
    {
        if (k & 1LL)
            r = russian(r, a, m);
        a = russian(a, a, m);
        k >>= 1LL;
    }
    return r;
}

ll russian(ll a, ll k, ll m)
{
    ll r = 0LL;
    while (k)
    {
        if (k & 1LL)
            r = (r + a) % m;
        a = (a + a) % m;
        k >>= 1LL;
    }
    return r;
}

ll _gcd(ll a, ll b)
{
    while (b)
        swap(a %= b, b);
    return a;
}

ll _lcm(ll a, ll b)
{
    return a / _gcd(a, b) * b;
}

ll extgcd(ll a, ll b, ll& k, ll& l)
{
    if (b == 0)
    {
        k = 1; l = 0;
        return a;
    }
    ll res = extgcd(b, a % b, l, k);
    l -= a / b * k;
    return res;
}

ll _inv(ll a, ll p)
{
    return fastpow(a, p - 2, p);
}
