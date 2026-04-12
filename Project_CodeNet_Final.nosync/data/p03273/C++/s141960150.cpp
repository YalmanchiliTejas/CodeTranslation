#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
typedef unsigned long long int ull;
typedef long long lint;
 
int main(void){
    int H,W;
    cin >> H >> W;
    char grid[H][W];
    bool check[H][W]={};
    bool line[H]={};
    rep(i,H) rep(j,W) cin >> grid[i][j];
    rep(i,H){
        bool che=0;
        rep(j,W) if(grid[i][j]=='#') che=1;
        if(che==0) rep(j,W) check[i][j]=1;
        if(che==0) line[i]=1;
    }
    rep(i,W){
        bool che=0;
        rep(j,H) if(grid[j][i]=='#') che=1;
        if(che==0) rep(j,H) check[j][i]=1;
    }
    rep(i,H){
        rep(j,W) if(check[i][j]==0) cout << grid[i][j];
        if(line[i]==0) cout << endl;
    }
}