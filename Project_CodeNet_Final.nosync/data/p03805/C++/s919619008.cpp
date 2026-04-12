#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(i) begin(i), end(i)

const int INF = 0x3fffffff;
const ll MINF = 0x7fffffffffff;
const ld DINF = numeric_limits<ld>::infinity();
const int MOD = 1000000007;
const int MODD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;

template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }

ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll pow_mod(ll n,ll k,ll m){ll r = 1;for(; k > 0;k >>= 1) {if (k & 1) r = (r * n) % m; n = (n * n) % m;}return r;}

//ここから。
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<bool>> rt(N,vector<bool> (N,false));
    vector<int> memo(N-1);
    iota(all(memo),1);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        rt[a-1][b-1] = true;
        rt[b-1][a-1] = true;
    }
    ll ans = 0;
    do {
        bool state = false;
        if(rt[0][memo[0]]){
            state = true;
            for(int i=1;i < N-1;i++){
                if(!rt[memo[i-1]][memo[i]]){
                    state = false;
                    break;
                }
            }
        }
        if(state) ans++;
    } while( next_permutation(memo.begin(), memo.end()) );     // 次の順列を生成

    cout << ans << endl;
}