#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cout << a[i] << " "; cout << "\n"; }
template<class T> void verr(const vector<T>& v){ for(auto& a : v) cout << a << " "; cout << "\n"; }
ll dbgt = 1; void err() { cout << "passed " << dbgt++ << "\n"; }
template<class H, class... T> void err(H&& h,T&&... t){ cout<< h << (sizeof...(t)?" ":"\n"); if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N;
    cin >> N;
    vl A(N);
    rep(i, N) cin >> A[i];

    bool isz = true;
    rep(i, N) if (A[i] > N-1) isz = false;
    if(isz){
        cout << 0 << endl;
        return 0;
    }

    bool sf = false;
    ll cnt = 0;
    vl C(N);
    while(!sf){
        rep(i, N) C[i] = A[i] / N;
        ll sum = accumulate(all(C), 0ll);

        rep(i, N){
            A[i] -= C[i] * N;
            A[i] += (sum - C[i]);
        }
        bool isok = true;
        rep(i, N) if (A[i] > N - 1) isok = false;
        if (isok) sf = true;

        cnt+=sum;
    }
    cout << cnt << endl;
}