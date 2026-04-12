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

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
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
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int A, B, C[12][12], D[101][101], DX[12][12], DY[12][12], NV, V[303][303], K=100;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    rep(i,303)rep(j,303) V[i][j]=-1;
    cin>>A>>B;
    rep1(x,A)rep1(y,B) cin>>C[x][y];
    
    vector<int> Xs, Ys;
    NV=1;
    Xs.push_back(NV);
    rep(i,K){
        V[NV][NV+1]=-2;
        NV++;
        Xs.push_back(NV);
    }
    
    NV++;
    Ys.push_back(NV);
    rep(i,K){
        V[NV+1][NV]=-3;
        NV++;
        Ys.push_back(NV);
    }
    
    rep(x,K+1)rep(y,K+1){
        int ret=0;
        rep1(i,A)rep1(j,B){
            ret=max(ret,C[i][j]-x*i-y*j);
        }
        D[x][y]=V[Xs[x]][Ys[y]]=ret;
    }
    
    rep1(i,A)rep1(j,B){
        int mi=1010;
        rep(x,K+1)rep(y,K+1){
            mi=min(mi,x*i+j*y+D[x][y]);
        }
        if(mi!=C[i][j]){
            cout1("Impossible");
            return 0;
        }
    }
    
    int cnt=0;
    rep(x,303)rep(y,303) if(V[x][y]!=-1) cnt++;
    cout1("Possible");
    cout2(NV,cnt);
    rep(x,303)rep(y,303) if(V[x][y]!=-1){
        cout<<x<<" "<<y<<" ";
        if(V[x][y]==-2) cout1("X");
        if(V[x][y]==-3) cout1("Y");
        if(V[x][y]>=0) cout1(V[x][y]);
    }
    cout2(Xs[0],Ys[0]);
}