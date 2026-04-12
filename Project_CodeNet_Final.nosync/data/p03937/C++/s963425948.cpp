#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;



int main(){
    
    int H,W;
    cin>>H>>W;
    int t[9][9];
    rep(i,0,9)rep(j,0,9)t[i][j]=0;

    char c[9][9];
    rep(i,0,9)rep(j,0,9)c[i][j]='.';
    
    rep(i,0,H){
        rep(j,0,W)cin>>c[i][j];
    }
    if(c[0][0]!='#'||c[H-1][W-1]!='#'){
        cout<<"Impossible"<<endl;
        return 0;
    }
    t[0][0]=1;t[H-1][W-1]=1;

    int nowx=0,nowy=0;
    while(1){
        if(nowx==H-1&&nowy==W-1)break;
        if(c[nowx+1][nowy]=='#'&&c[nowx][nowy+1]=='.'){
            t[nowx+1][nowy]=1;
            nowx++;
           // cout<<"d"<<nowx<<nowy;
        }
        else if(c[nowx][nowy+1]=='#'&&c[nowx+1][nowy]=='.'){
            t[nowx][nowy+1]=1;
            nowy++;
          //  cout<<"r"<<nowx<<nowy;
        }
        else{
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    rep(i,0,H){
        rep(j,0,W){
            if(c[i][j]=='#'&&t[i][j]==0){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
}




