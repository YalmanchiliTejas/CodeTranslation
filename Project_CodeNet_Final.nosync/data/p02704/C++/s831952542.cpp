#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define repa(i,n) for (auto& i: n)

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cerr << a[i] << " "; cerr << "\n" << flush; }
ll dbgt = 1; void err() { cerr << "passed " << dbgt++ << "\n" << flush; }
template<class H, class... T> void err(H&& h,T&&... t){ cerr<< h << (sizeof...(t)?" ":"\n") << flush; if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

const ll INF = 5e18;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
//--------------------------------------------------------------------------------//
using ull = unsigned long long;
bool S[500], T[500];
ull U[500], V[500], cnti[500][64], cntj[500][64];
ull unow[500], vnow[500];
ull ans[500][500];
ull mask = 0xffffffffffffffff;
int main() {
    init();
    ull N;
    cin >> N;
    rep(i, N) cin >> S[i];
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> U[i];
    rep(i, N) cin >> V[i];

    rep(i,N){
        if (S[i]) continue;
        rep(j, N) ans[i][j] = U[i];
    }
    rep(i,N){
        if (T[i]) continue;
        rep(j, N) ans[j][i] |= V[i];
    }

    //check
    rep(i,N){
        if (S[i]) continue;
        ull C = mask;
        rep(j, N) C &= ans[i][j];
        if(C!=U[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i,N){
        if (T[i]) continue;
        ull C = mask;
        rep(j, N) C &= ans[j][i];
        if(C!=V[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    rep(i,N){
        rep(j,N){
            if (S[i] and T[j]) ans[i][j] = U[i] & V[j];
            if (S[i]) unow[i] |= ans[i][j];
            if (T[j]) vnow[j] |= ans[i][j];
        }
    }

    //check
    rep(i,N){
        bool isok = true;
        if (S[i] and (unow[i] | U[i]) != U[i]) isok = false;
        if (T[i] and (vnow[i] | V[i]) != V[i]) isok = false;
        if(!isok){
            cout << -1 << endl;
            return 0;
        }
    }

    rep(i,N)rep(j,N){
        rep(b,64){
            if (ans[i][j] & (1ull << b)) cnti[i][b]++, cntj[j][b]++;
        }
    }
    
    rep(i,N)rep(j,N){
        if(S[i] and !T[j]){
            ull B = unow[i] ^ U[i], a = 0;
            rep(b,64){
                if ((B & (1ull << b)) and cntj[j][b] < N - 1) ans[i][j] |= 1ull << b, unow[i] |= 1ull << b, cntj[j][b]++;
            }
        }
        else if(!S[i] and T[j]){
            ull B = vnow[j] ^ V[j];
            rep(b,64){
                if ((B & (1ull << b)) and cnti[i][b] < N - 1) ans[i][j] |= 1ull << b, vnow[j] |= 1ull << b, cnti[i][b]++;
            }
        }
    }


    rep(i,N){
        rep(j, N) cout << ans[i][j] << " ";
        cout << '\n';
    }

    
    
}