#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    ll n, m;    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    rep(i, m){
        ll a, b;    cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = true;
    }
    vector<ll> chk(n);
    rep(i, n)   chk[i] = i;
    ll res=0;
    do{
        bool flag=true;
        if(chk[0]) break;
        rep(i, n-1){
            flag &= g[chk[i]][chk[i+1]];
        }
        res += flag;
    }while(next_permutation(ALL(chk)));
    cout << res << endl;
}
