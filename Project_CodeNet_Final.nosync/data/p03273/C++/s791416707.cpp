#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int H,W;cin>>H>>W;
    char A[H][W];
    map<int,int>hmemo;
    map<int,int>wmemo;
    REP(i,H){
        REP(j,W)cin>>A[i][j];
    }
    REP(i,H){
        bool ok=true;
        REP(j,W){
            if(A[i][j]=='#'){
                ok=false;
                break;
            }
        }
        if(ok)hmemo[i]++;
    }
    REP(j,W){
        bool ok=true;
        REP(i,H){
            if(A[i][j]=='#'){
                ok=false;
                break;
            }
        }
        if(ok)wmemo[j]++;
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(hmemo[i]==0&&wmemo[j]==0)cout<<A[i][j];
        }
      	if(hmemo[i]==0)cout<<endl;  
    }
}