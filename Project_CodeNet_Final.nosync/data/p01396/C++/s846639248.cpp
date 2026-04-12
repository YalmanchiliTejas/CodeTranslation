#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class T> istream& operator>>(istream& is,vector<T>& v) { for(T& t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { for(T t:v){os<<t<<" ";} os<<"\n"; return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

class Bipartite_matching {
    int n;
    vvi G;
    vi match;
    vb used;
    bool dfs(int v) {
        used[v] = true;
        for(int u : G[v]) {
            int w = match[u];
            if(w < 0 || !used[w] && dfs(w)) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

public:
    Bipartite_matching(int n):n(n),G(n),match(n),used(n) {}
    void add_edge(int v,int u) {
        G[v].pb(u);
        G[u].pb(v);
    }
    int max_matching() {
        int res = 0;
        match.assign(n,-1);
        rep(i,n) {
            if(match[i] >= 0) continue;
            used.assign(n,false);
            if(dfs(i)) res++;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int H,W;
    cin >> H >> W;
    vvi h(H,vi(W));
    cin >> h;
    rep(_,2) {
        Bipartite_matching bp(2*H);
        vb v(H,true);
        rep(i,H) rep(j,H) {
            if(i == j) continue;
            bool ok = true;
            rep(k,W) if(h[i][k] > h[j][k]) ok = false;
            if(ok) bp.add_edge(i,j+H);
            else v[j] = false;
        }
        bool flag = false;
        rep(i,H) if(v[i]) flag = true;
        if(!flag) {
            YES(false);
            return 0;
        }
        if(H-bp.max_matching() > 2) {
            YES(false);
            return 0;
        }
        vvi nh(W,vi(H));
        rep(i,H) rep(j,W) nh[j][i] = h[i][j];
        swap(H,W);
        swap(h,nh);
    }
    YES(true);
}

