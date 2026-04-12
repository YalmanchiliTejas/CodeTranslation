#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

int n, m;
int res=0;
vector<vector<int> > to;
vector<bool> seen;

void dfs(int u){
    bool can = true;
    REP(i,n){
        if( seen[i]==false && i!=u ) can = false;
    }

    if(can){
        res++;
        return;
    }

    //フラグを立てる
    seen[u] = true;
    for(auto x : to[u]){
        if(seen[x] != false) continue;
        dfs(x);
    }
    //フラグを下げる
    seen[u] = false;
}

int main() {
    cin >> n >> m;
    to.resize(n);
    seen.resize(n, false);
    REP(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].PB(b);
        to[b].PB(a);        
    }

    dfs(0);

    cout << res << endl;
}