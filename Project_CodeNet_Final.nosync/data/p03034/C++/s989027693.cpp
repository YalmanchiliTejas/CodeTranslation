#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rea(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())
#define PRINT(V) for (auto v:(V)) {cerr << v << " ";} cerr << endl
#define dump(x) cerr << #x << " : " << (x) << endl
#define dump2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
inline ll GCD(ll a, ll b){return b ? GCD(b, a % b) : a;}
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
/* END OF TEMPLATE */

// 解説
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vll s(N);
    rep(i, N){
        cin >> s[i];
    }
    ll ans = 0;
    rea(c, 1, N-1){
        ll score = 0;
        set<ll> st;
        st.clear();
        rep(k, N-1){
            ll A = N-1-k*c;
            ll B = A-c;
            if(B <= 0) break;
            if(st.find(N-1-k*c) != st.end() || st.find(k*c) != st.end())
                break;
            if(N-1-k*c == k*c) break;
            if(A <= 0 || A <= B) continue;
            score += s[N-1-k*c] + s[k*c];
            st.emplace(N-1-k*c);
            st.emplace(k*c);
            ans = max(ans, score);
        }
    }
    cout << ans << endl;
    return 0;
}