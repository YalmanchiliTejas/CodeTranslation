#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};

vector<int> G[1<<17];
vector<int> dp(1<<17,0);
int r = 3;

int dfs(int u,int v){
    int ret = 0;
    for(auto g:G[u]){
        if(g == v) continue;
        chmax(ret, dfs(g, u));
    }
    return dp[u] = ret + 1;
}

void dfs2(int u,int v,P x){
    vector<P> vv;
    vv.pb(mp(0, -1));
    for(auto g:G[u]){
        if(g == v){
            vv.pb(x);
        }
        else{
            vv.pb(mp(dp[g], g));
        }
    }
    sort(RALL(vv));
    for(auto g:G[u]){
        if(g == v) continue;
        if(g == vv[0].sc){
            dfs2(g, u, mp(vv[1].fs + 1, u));
        }
        else{
            dfs2(g, u, mp(vv[0].fs + 1, u));
        }
    }
    if(vv.size() >= 4){
        int a = vv[0].fs, b = vv[1].fs, c = vv[2].fs;
        chmax(r, a + c + (a != c));
    }
}


int main(){
    int n;cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a,b;cin >> a >> b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0,-1);
    dfs2(0,-1,mp(0,-1));
    string ans(n, '1');
    for (int i = 3; i < r; i++) {
        ans[i - 1] = '0';
    }
    cout << ans << endl;
    return 0;
}

