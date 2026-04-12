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

int main() {
    init();
    ll N;
    cin >> N;
    string S;
    cin >> S;

    rep(i,4){
        bool tok = true;
        vc<bool> B(N);
        if (i & 1) B[0] = true;
        if (i & 2) B[1] = true;

        repe(i, 1, N){
            ll l = i - 1, r = (i + 1) % N;
            
            // wolf
            if(B[i]){
                B[r] = (S[i] == 'o' ? !B[l] : B[l]);
            }
            // sheep
            else{
                B[r] = (S[i] == 'o' ? B[l] : !B[l]);
            }
        }

        if(B[0]){
            if((S[0]=='o' and B[1]==B[N-1]) or (S[0]=='x' and B[1]!=B[N-1]))
                tok = false;
        }
        else{
            if((S[0]=='o' and B[1]!=B[N-1]) or (S[0]=='x' and B[1]==B[N-1]))
                tok = false;
        }
        if(B[1]){
            if((S[1]=='o' and B[2]==B[0]) or (S[1]=='x' and B[2]!=B[0]))
                tok = false;
        }
        else{
            if((S[1]=='o' and B[2]!=B[0]) or (S[1]=='x' and B[2]==B[0]))
                tok = false;
        }
        

        if(tok){
            string ans;
            rep(i, N) ans += (B[i] ? 'W' : 'S');
            cout << ans << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}