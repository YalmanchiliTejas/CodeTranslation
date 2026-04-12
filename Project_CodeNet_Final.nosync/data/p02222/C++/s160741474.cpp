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
vector<int> dp(1<<17);

int dfs(int u,int v){
    int ret = 0;
    for(auto g:G[u]){
        if(g == v) continue;
        ret = max(ret, dfs(g, u));
    }
    return dp[u] = ret + 1;
}

int n;
int l = 3;

void dfs2(int u, int v, P x){
    vector<P> vv;
    for(auto g:G[u]){
        if(g == v){
            vv.pb(x);
        }
        else{
            vv.pb(mp(dp[g],g));
        }
    }
    sort(RALL(vv));
    for(auto g:G[u]){
        if(g == v) continue;
        if(vv[0].sc == g){
            if(vv.size() == 1) dfs2(g, u, mp(1, u));
            else dfs2(g, u, mp(vv[1].fs + 1, u));
        }
        else{
            dfs2(g, u, mp(vv[0].fs + 1, u));
        }
    }
    if(vv.size() >= 3){
        int a = vv[0].fs, b = vv[1].fs, c = vv[2].fs;
        for (int k = l; k < n; k++) {
            if(k > a + c) break;
            else if(a + c == k && k - b == k - c && (k - c) * 2 == k) break;
            l++;
        }
    }
    return;
}



int main(){
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n-1; i++) {
        int a,b;cin >> a >> b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0,0);
    dfs2(0,0,mp(0,0));
    for (int i = 1; i <= 2; i++) {
        cout << 1;
    }
    for (int i = 3; i < l; i++) {
        cout << 0;
    }
    for (int i = l; i <= n; i++) {
        cout << 1;
    }
    cout << endl;
    return 0;
}



