#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int H,W;cin>>H>>W;
    vector<string> v(H);
    REP(i,H)cin>>v[i];
    bool f=true;
    REP(i,H)REP(j,W){
        if(v[i][j]=='.')continue;
        else{
            if(i==0 && j==0){
                if(v[0][1]=='#'&&v[1][0]=='#'){
                    f=false;break;
                }
            }else if(i==H-1 && j==W-1){
                if(v[H-2][W-1]=='#' && v[H-1][W-2]=='#'){
                    f=false;break;
                }
            }else{
                if((i-1>=0 && v[i-1][j]=='#') && (j-1>=0 && v[i][j-1]=='#')){
                    f=false;break;
                }
                if((i+1<=H-1 && v[i+1][j]== '#') && (j+1<=W-1 && v[i][j+1]=='#')){
                    f=false;break;
                }
            }
        }
    }
    if(f)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}