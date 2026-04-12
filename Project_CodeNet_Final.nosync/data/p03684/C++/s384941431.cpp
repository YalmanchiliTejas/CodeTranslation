#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
 
using namespace std;
int MOD = 1000000007;
#define N 100010
int par[N];
int rnk[N];

void init(int n){
    for(int i=0;i<n;i++){
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rnk[x] < rnk[y]) par[x] = y;
    else{
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x,int y){
    return find(x) == find(y);
}


signed main(){

    int n;
    cin >> n;
    init(n);

    vector<pair<int,int>> px(n);
    vector<pair<int,int>> py(n);
    vector<pair<int,pair<int,int>>> e(2*(n-1));
    
    rep(i,n){
        int x,y;
        cin >> x >> y;
        px[i] = MP(x,i);
        py[i] = MP(y,i);
    }
    SORT(px);
    SORT(py);
    rep(i,n-1){
        e[i] = MP(px[i+1].fi-px[i].fi,MP(px[i+1].se,px[i].se));
        e[n-1+i] = MP(py[i+1].fi-py[i].fi,MP(py[i+1].se,py[i].se));
    }
    SORT(e);
    int ans = 0;
    rep(i,2*(n-1)){
        if(!(same(e[i].se.fi,e[i].se.se))){
            ans += e[i].fi;
            unite(e[i].se.fi,e[i].se.se);
        }
    }

    cout << ans << endl;

    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://arc076.contest.atcoder.jp/tasks/arc076_b