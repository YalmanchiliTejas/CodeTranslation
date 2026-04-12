#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPr(i, n) for(int i = (n)-1; i >= 0; --i)
#define FORq(i, m, n) for(int i = (m); i <= (n); ++i)
#define FORqr(i, m, n) for(int i = (n); i >= (m); --i)
#define MP make_pair
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x, 0, sizeof(x))
#define FILL(x, y) memset(x, y, sizeof(x))
#define MM(x) memset(x, -1, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define DB(x) cerr << #x << " = " << x << endl
#define DB2(x, y)                                                              \
    cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG                                                                  \
    int x12345;                                                                \
    cin >> x12345;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
const long long MOD = 1e9 + 7;

///////////////////////////////////////////////
// for template
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////
/// ⸜( ⌓̈ )⸝ ///

int main() {
    ll N,X,M; cin >> N >> X >> M;
    vector<ll> index(M + 2);
    vector<ll> XX(M+2);

    REP(i,M+2){index[i] = -1;}
    ll Xs = X;
    ll nsum = 0;
    ll lstart,lend;
    lstart = -1;
    lend = -1;
    REP(i,100000){
        if (i) Xs = (Xs * Xs) % M;
        nsum += Xs;
        XX[i] = Xs;
        //DB2(i,XX[i]);
        //DB2(i,nsum);
        if (index[Xs] != -1){
            lstart = index[Xs];
            lend = i - 1;
            break;
        }
        index[Xs] = i;
    }
    //DB2(lstart,lend);

    ll ans = 0;
    if (lstart != -1){
        ll loopsize = lend - lstart + 1;
        ll loopcount = (N - lstart) / loopsize;
        ll rest = (N - lstart) % loopsize;

        REP(i,lstart){
            ans += XX[i];
        }

        REP(i,rest){
            ans += XX[lstart+i];
        }

        ll loopsum = 0;
        FORq(i,lstart,lend){
            loopsum += XX[i];
        }
        ans += loopsum * loopcount;
    }else{
        REP(i,N){
            ans += XX[i];
        }
    }

    cout << ans << endl;
}