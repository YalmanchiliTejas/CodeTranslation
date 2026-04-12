#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n, m, cnt = 0;
    cin >> n >> m;
    vvi adj(n, vi(n, 0));
    rep(i, m){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    vi np(n-1);
    rep(i, n-1) np[i] = i+1;
    do{
        if(adj[0][np[0]] != 1) continue;
        bool chk = true;
        for(ll i=0; i<np.size()-1; i++){
            if(adj[np[i]][np[i+1]] != 1) chk = false;
        }
        if(chk) cnt++;
    } while(next_permutation(all(np)));
    cout << cnt << endl;
}