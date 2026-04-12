#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
using intmap = map<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const int MOD = 998244353;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
inline bool bit (ll b, ll i) { return b & (1 << i); }
inline ll ceiv (ll a, ll b) { return (a + b - 1) / b; }
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define debug(x) cerr << #x << ": " << x << '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

int modpow(int a, int n, int m = MOD){
    ll ret = 1;
    while(n>0){
        if(n&1) ret = (ret*a) % m;
        a = (a*a) % m;
        n >>= 1;
    }
    return ret % m;
}

signed main(){
    int n, x, m;
    cin >> n >> x >> m;
    map<int, int> mp;
    vi mem;
    int ans = 0;
    
    rep(i,n){
        mp[x] = i;
        mem.emplace_back(x);
        
        ans = ans + x;
        x = mod(x * x, m);
        
        if(mp.count(x)){

            int tmp = 0;
            int loopsize = mem.size() - mp[x];

            reps(j, mp[x], mem.size()-1){
                tmp += mem[j];
            }

            int loopleft = n - (i+1);
            ans += (loopleft / loopsize) * tmp;

            rep(j, loopleft % loopsize) {
                ans += x;
                x = mod(x * x, m);
            }

            break;
        }
    }
    
    cout << ans << endl;
}