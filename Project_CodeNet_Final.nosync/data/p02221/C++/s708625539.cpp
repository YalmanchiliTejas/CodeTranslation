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

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//
ll db[1 << 18][19];
int main() {
    init();
    ll N;
    string s;
    cin >> N >> s;
    s = '#' + s;
    ll N2 = 1 << N;
    vl A(2*N2);
    rep(i, N2) cin >> A[i];
    rep(i, N2) A[i]--, A[i + N2] = A[i];

    rep(i, N2) db[i][0] = A[i];
    rep(i,N){
        rep(j,N2){
            ll a = db[j][i], b = db[(j+(1<<i))%N2][i];
            if (a > b) swap(a, b);
            if(s[b-a]=='1'){
                db[j][i + 1] = b;
            }else{
                db[j][i + 1] = a;
            }
        }
    }
    // rep(i,N2){
    //     rep(j, N + 1) cout << db[i][j] << " ";
    //     cout << endl;
    // }
    rep(i,N2){
        cout << db[i][N]+1 << "\n";
    }
    
}
