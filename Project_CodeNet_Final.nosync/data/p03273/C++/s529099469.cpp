#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair

void solve(int H, int W, vector<string>& a) {
    set<int> rs, cs;
    rep(r,H) {
        bool active = false;
        rep(c,W) if (a[r][c] == '#') { active = true; break; }
        if (active) rs.insert(r);
    }
    rep(c,W) {
        bool active = false;
        rep(r,H) if (a[r][c] == '#') { active = true; break; }
        if (active) cs.insert(c);
    }
    rep(r,H) {
        if (!found(rs, r)) continue;
        rep(c,W) {
            if (!found(cs, c)) continue;
            putchar(a[r][c]);
        }
        putchar('\n');
    }
}

int main() {
    int H, W; cin >> H >> W;
    vector<string> a(H);
    rep(i,H) cin >> a[i];
    solve(H,W,a);
    return 0;
}
