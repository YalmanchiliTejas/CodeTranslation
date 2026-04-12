#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
// #define DEBUG 100
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll >;
 
const ll oo = 1e18 + 7;
const ll mod = 1e9 + 7,maxn = 1e5 + 100, maxm = 1e5+100;
const double PI = acos(-1);

int main (){
    ios_base::sync_with_stdio(false);
    ll n, x, m, tam;
    cin >> n >> x >> m;
    vector<ll> vs;
    set<ll> st;

    while (!st.count(x)){
        st.insert(x);
        vs.push_back(x);
        x = (x*x)%m;
    }
    for (int i=0; i<(int)vs.size(); i++){
        if (vs[i] == x) {
            tam = i;
            break;
        }
        if (i) vs[i]+=vs[i-1];
    }
    ll ans, t = vs.size();

    if (n <= tam){
        cout << vs[n-1] << endl;
        return 0;
    }

    if (tam) ans = vs[tam-1];
    else ans = 0;
    n -= tam;

    for (ll i=tam;i<t;i++){
        ans += n/(t-tam)*vs[i];
        if (i - tam + 1 <= n%(t-tam))ans+=vs[i];
    }
    cout << ans << endl;
    return 0;
}