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
const ll MOD = 100007LL;
void in() {}
template<class Head, class... Tail>
void in(Head&& head, Tail&&... tail) { cin >> head; in(move(tail)...); }
#define IN(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define TIN(T, ...) T __VA_ARGS__; in(__VA_ARGS__)
#define VIN(T, v, n) V<T> v(n); for(auto& _elem:v)cin>>_elem
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if (a>b) {a=b; return 1;} return 0;}
template<class T>
string join(vector<T>& v, string delim="") { ostringstream os; rep(i,v.size())i?os<<delim<<v[i]:os<<v[0]; return os.str(); }
#pragma endregion RegionDefs

ll m = 1000000007;
ll inv(ll v) {
    ll a = v, b = m, c = 1, d = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b; swap(a, b);
        c -= t * d; swap(c, d);
    }
    c %= m;
    if (c < 0) c += m;
    return c;
}

void solve()
{
    IN(n);
    VIN(ll, a, n);
    ll s = 0;
    rep(i, n) {
        s += a[i];
        s %= m;
    }
    ll ans = 0;
    rep(i, n) {
        ans += a[i] * ((s - a[i] + m) % m);
        ans %= m;
    }
    cout << (ans * inv(2) + m) % m << endl;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(numeric_limits<double>::max_digits10);

    solve();

    return 0;
}