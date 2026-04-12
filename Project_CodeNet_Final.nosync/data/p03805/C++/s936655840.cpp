#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;
vector<vector<ll>> G(10);
vector<ll> memo(10);
ll N;

ll dfs(ll v, ll p){
    ll res = 0;
    bool flag = false;
    rep(i,N){
        if(memo[i] == 0){
            flag = true;
            break;
        }
    }
    if(!flag){
        return 1;
    }
    for(auto& u:G[v]){
        if(u == p) continue;
        if(memo[u] != 0) continue;
        memo[u] = 1;
        res += dfs(u,v);
        memo[u] = 0;
    }
    return res;
}
int main(){
    ll M;
    cin >> N >> M;
    ll a,b;
    rep(i,M){
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    memo[0] = 1;
    cout << dfs(0,-1) << endl;
}
