#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double EPS = 1e-8;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

// #define DEBUG_MODE
#ifdef DEBUG_MODE
#define dump(x) cout << #x << " : " << x << " "
#define dumpL(x) cout << #x << " : " << x << '\n'
#define LINE cout << "line : " << __LINE__ << " "
#define LINEL cout << "line : " << __LINE__ << '\n'
#define dumpV(v) cout << #v << " : ["; for(auto& t : v) cout << t << ", "; cout<<"]" << " "
#define dumpVL(v) cout << #v << " : ["; for(auto& t : v) cout << t << ", "; cout<<"]" << endl
#define STOP assert(false)
#else
#define dump(x) 
#define dumpL(x) 
#define LINE 
#define LINEL 
#define dumpV(v) 
#define dumpVL(v) 
#define STOP assert(false)
#endif
#define mp make_pair
 
namespace std {
template<class S, class T>
ostream &operator <<(ostream& out, const pair<S, T>& a) {
    out << '(' << a.fi << ", " << a.se << ')';
    return out;
}
}

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >>x >> y;
    ll ans = a * x + b * y;
    dumpL(ans);
    ll z = max(x, y) * 2;
    rep(i, z + 1) {
        ll tmp = 0;
        tmp += max(0LL, x - i/2) * a;
        tmp += max(0LL, y - i/2) * b;
        tmp += i * c;
        dump(i);dumpL(ans);
        chmin(ans, tmp);
    } 
    cout << ans << endl;
    return 0;
}