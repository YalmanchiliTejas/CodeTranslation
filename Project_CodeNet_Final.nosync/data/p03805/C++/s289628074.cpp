#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;


int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    rep(i, m) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> v(n);
    v[0] = 1;
    Rep(i, 1, n) v[i] = i+1;
    int ans = 0;
    do{
        if(v[0] != 1) break;
        bool all = true;
        rep(i, n-1) {
            bool one = false;
            for(int x : g[v[i]]) if(x == v[i+1]) one = true;
            if(!one) all = false;
        }
        if(all) ans++;
    }while(next_permutation(all(v)));

    cout << ans << endl;
}