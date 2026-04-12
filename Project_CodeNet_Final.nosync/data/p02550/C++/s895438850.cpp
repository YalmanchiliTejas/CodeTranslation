#pragma region RegionDefs
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define reps(i,l,r) for(int i=(l),i##_len=(r);i<i##_len;++i)
#define repr(i,l,r) for(int i=(r)-1,i##_left=(l);i>=i##_left;--i)
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
const ll INF = 1e9;
template<class T=ll> using V = vector<T>;
template<class T=ll> using PQ = priority_queue<T>;
template<class T=ll> using PQG = priority_queue<T, V<T>, greater<T>>;
const ll MOD = 1000000007LL;
void in() {}
template<class Head, class... Tail>
void in(Head&& head, Tail&&... tail) { cin >> head; in(move(tail)...); }
#define IN(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define TIN(T, ...) T __VA_ARGS__; in(__VA_ARGS__)
#define VIN(T, v, n) V<T> v(n); for(auto& _elem:v)cin>>_elem
#define VIND(T, v, n) V<T> v(n); for(auto& _elem:v)cin>>_elem,--_elem
#define OUT(x) cout << x;
#define OUTL(x) cout << x << endl;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if (a>b) {a=b; return 1;} return 0;}
template<class T>
string join(vector<T>& v, string delim="") { ostringstream os; rep(i,v.size())i?os<<delim<<v[i]:os<<v[0]; return os.str(); }
#pragma endregion RegionDefs

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

ll c[114514];

void solve()
{
    Bint n;
    cin >> n;
    IN(x, m);
    vector<ll> v;
    v.push_back(0);
    v.push_back(x);
    c[x] = 1;
    bool loop = false;
    ll ran = (ll)min((Bint)114514, n);
    for(int i = 2; i <= ran; ++i) {
        x = ((x % m) * (x % m)) % m;
        if (c[x] != 0) {
            loop = true;
            break;
        }
        c[x] = i;
        v.push_back(x);
    }
    ll res = 0;
    if (!loop) {
        rep(i, (ll)n+1) {
            res += v[i];
        }
        cout << res << endl;
        return;
    }
    rep(i, c[x]) {
        res += v[i];
    }
    n -= c[x] - 1;
    ll cicle = v.size() - c[x];
    ll sum = 0;
    reps(i, c[x], v.size()) sum += v[i];
    res += (ll)(n / cicle) * sum;
    rep(i, (ll)(n % cicle)) {
        res += v[c[x]+i];
    }
    cout << res << endl;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(numeric_limits<double>::max_digits10);

    solve();

    return 0;
}