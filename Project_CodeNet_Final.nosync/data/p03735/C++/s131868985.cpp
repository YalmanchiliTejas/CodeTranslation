#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    int X[N], Y[N];
    rep(i,N){
        cin>>X[i]>>Y[i];
        if(X[i]>Y[i]) swap(X[i],Y[i]);
    }
    
    // 全てのボールの最小値、最大値
    int all_min=*min_element(X,X+N);
    int all_max=*max_element(Y,Y+N);
    
    // 赤の最大値を最小に、青の最小値を最大に
    int Rmax=all_min, Bmin=all_max;
    rep(i,N){
        Rmax=max(Rmax,X[i]);
        Bmin=min(Bmin,Y[i]);
    }
    
    // 赤が全ボール最小値、青が全ボール最大値を取った時の最小値
    ll ret=1LL*(Rmax-all_min)*(all_max-Bmin);
    
    // 赤が全ボール最大値、最小値共に取った時、青の最大最小幅を最小にする
    vector<pii> vs(N);
    rep(i,N){
        vs[i].first=X[i];
        vs[i].second=Y[i];
    }
    
    sort(all(vs));
    int dif=all_max-all_min;
    int Bmax = vs.back().first; Bmin=all_max;
    
    rep(i,N){
        ret = min( ret, 1LL*dif*(Bmax-min(Bmin,vs[i].first)));
        if(Bmin>vs[i].second) Bmin=vs[i].second;
        if(Bmax<vs[i].second) Bmax=vs[i].second;
    }
    cout1(ret)
}