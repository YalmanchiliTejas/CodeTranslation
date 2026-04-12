#include <iostream>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mp make_pair
#define fname ""
#define fi first
#define se second
#define sz(a) (int)a.size()
#define pb push_back
#define fo(i,k,n) for(int i=k; (int)i<n; ++i)
#define rep(i,n,k) for(int i=n; (int)i>=k; --i)
#define all(v) v.begin(), v.end()
#define it ::iterator
#define forit(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)


int n;
vector<pair<pii, int>> cor1, cor2;
vector<pair<int, pii>> g;
bool u[100100];
vector<int> p(100100);

int dsu_get(int v){
    if (v== p[v])
        return v;
    return p[v] = dsu_get(p[v]);
    
}

void dsu_unit(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);
    if (rand() & 1){
        swap(a,b);
    }
    if(a!=b){
        p[a] = b;
    }
}

int main(){
    
    //freopen(fname"in", "r", stdin);
    //freopen(fname"out", "w", stdout);
    
    scanf("%d", &n);
    
    fo(i,0,n){
        int a,b;
        scanf("%d%d", &a,&b);
        a--, b--;
        cor1.pb(mp(mp(a,b), i));
        cor2.pb(mp(mp(b,a), i));
    }
    
    sort(all(cor1));
    sort(all(cor2));
    
    fo(i,0,n-1){
        g.pb(mp(cor1[i+1].fi.fi - cor1[i].fi.fi,mp(cor1[i].se, cor1[i+1].se)));
        g.pb(mp(cor2[i+1].fi.fi - cor2[i].fi.fi,mp(cor2[i].se, cor2[i+1].se)));
    }
    
    int cost = 0;
    vector<pii> res;
    
    sort(all(g));
    
    p.resize(n);
    fo(i,0,n){
        p[i] = i;
    }
    
    fo(i,0,2*(n-1)){
        int a = g[i].se.fi,  b = g[i].se.se,  l = g[i].fi;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
            res.pb(g[i].se);
            dsu_unit(a, b);
        }
    }
    
    cout<<cost;
    
    
    return 0;
}







