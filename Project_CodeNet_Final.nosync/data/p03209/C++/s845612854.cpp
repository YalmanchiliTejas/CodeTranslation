#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

ll getNum(ll level, ll X, const vector<ll>& len) {
    if (level == 0) return 1;

    ll middle = (len[level]-1)/2 + 1;
    if (X == 1) return 0;
    else if (X < middle) return getNum(level-1, X-1, len);
    else if (X == middle) return getNum(level-1, X-2, len) + 1;
    else if (X < len[level]) return getNum(level-1, len[level-1], len) + 1 + getNum(level-1, X - middle, len);
    else return 2 * getNum(level-1, len[level-1], len) + 1;
}

void solve(long long N, long long X){
    vector<ll> len(N+1);
    len[0] = 1;
    rep(i,1,N+1) {
        len[i] = len[i-1] * 2 + 3;
    }
    cout << getNum(N, X, len) << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    solve(N, X);
    return 0;
}
