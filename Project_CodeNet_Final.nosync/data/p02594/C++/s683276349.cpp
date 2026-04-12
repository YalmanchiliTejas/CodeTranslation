/*It’s going to be hard,
but hard does not mean impossible.*/

#include <bits/stdc++.h>

// definitions
#define __Imperial_Lord__ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _cps CLOCKS_PER_SEC
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i, l, r) for (long long i = (l); i < (long long)(r); i++)
#define repb(i, r, l) for (long long i = (r); i > (long long)(l); i--)
#define acc(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define high(x) __builtin_popcountll(x)
#define pb push_back
#define pf push_front
#define p0(a) cout << a << " "
#define p1(a) cout << a << "\n"
#define p2(a, b) cout << a << " " << b << "\n"
#define p3(a, b, c) cout << a << " " << b << " " << c <<"\n"
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d <<"\n"
#define exec cerr<<"Time taken : "<<(ld)(clock())/_cps<<"s"<<"\n"
#define mod1 998244353
#define mod 1000000007
#define pi 3.1415926535897932384

using namespace std;

// alias name for common data types
typedef vector<long long> vl;
typedef vector<long double> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector< pair<long long, long long> > vp;
typedef vector<tuple<long long , long long , long long> > vtup;
typedef deque <long long> dql;
typedef deque <char> dqc;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll INF = LONG_LONG_MAX;

template <class ...Args>
istream &read_args(Args &...args) {return (cin >> ... >> args);}
#define read(...)   __VA_ARGS__; read_args(__VA_ARGS__)

// cin and cout overloaded for vectors
template<typename T>    istream& operator>>(istream& is,  vector<T>& v)
{
    for (auto& i : v)
        is >> i;
    return is;
}
template<typename T>    ostream& operator<<(ostream& os,  vector<T>& v)
{
    for (auto& i : v)
        os << i << ' ';
    return os;
}



// code beigns in main
int main()
{
    __Imperial_Lord__
    ll t = 1;
    // cin >> t;

    while(t--)
    {
        ll read(x);
        if(x>=30) p1("Yes");
        else p1("No");
    }
    exec;
}