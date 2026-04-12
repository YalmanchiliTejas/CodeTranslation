#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;
const ll MOD=1000000007;
int V;
const int MAX_V=100000;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v){
    G[u].pb(v); G[v].pb(u);
}

bool dfs(int v){
    used[v]=true;
    for(int &to : G[v]){
        int w=match[to];
        if(w<0||!used[w]&&dfs(w)){
            match[v]=to;
            match[to]=v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(){
    int res=0;
    memset(match, -1, sizeof(match));
    rep(v,0,V){
        if(match[v]<0){
            memset(used, 0, sizeof(used));
            if(dfs(v)){
                res++;
            }
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>V;
    rep(i,0,V){
        int a,b;
        cin>>a>>b;
        add_edge(a-1, b-1);
    }
    int k=bipartite_matching();
    cout <<(k*2==V?"Second":"First")<<"\n";
}
