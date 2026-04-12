#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;

int main() {
    ll n,m; cin >> n >> m;
    vvl G(n);
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,n) sort(all(G[i]));
    vl nxt(n-1);
    rep(i,n-1) nxt[i] = i+1;
    ll ans = 0;
    do{
        ll u = 0;
        bool flag = true;
        rep(i,n-1){
            if(!binary_search(all(G[u]),nxt[i])){
                flag = false;
                break;
            }
            u = nxt[i];
        }
        if(flag) ans++;
    }while(next_permutation(all(nxt)));
    cout << ans << endl;
}