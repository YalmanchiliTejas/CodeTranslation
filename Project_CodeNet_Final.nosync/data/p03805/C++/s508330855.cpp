#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((int)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;


////////////////////////////////////////////////////////

bool g[10][10];

int main() {
    ll n, m; cin >> n >> m;
    rep(i, 0, m){
        ll a, b; cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    Vl v = {};
    ll cnt = 0;
    Rep(i, 1, n) v.push_back(i);
    // Rep(i, 1, n){
    //     Rep(j, 1, n) cout << g[i][j] << " ";
    //     cout << endl;
    // }
    do{
        bool f = true;
        rep(i, 0, sz(v)-1){
            if(!g[v[i]][v[i+1]]) f = false;
        }
        if(f) cnt++;
    }while(next_permutation(v.begin()+1, v.end()));
    co(cnt);

    return 0;
}
