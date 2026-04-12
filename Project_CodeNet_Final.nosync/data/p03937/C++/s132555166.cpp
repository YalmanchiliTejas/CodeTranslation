#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

const ll MOD = 1e9+7;


signed main(){
    ll h,w;
    cin >> h >> w;
    char c[h][w] = {};
    ll cnt = 0;
    rep(i,0,h){
        rep(j,0,w){
            cin >> c[i][j];
            if(c[i][j] == '#') cnt++;
        }
    }

    if(cnt == h+w-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}
