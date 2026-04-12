#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int H,W;
    char fld[10][10];
    cin>>H>>W;
    rep(i,H)cin>>fld[i];

    bool vis[10][10]={};
    int y=-1,x;
    rep(i,H){
        rep(j,W){
            if(fld[i][j]=='#'){
               y=i,x=j;
               break;
            }
        }
        if(y!=-1)break;
    }

    vis[y][x]=true;
    while(true){
        bool f1=false,f2=false;
        if(y+1<H&&fld[y+1][x]=='#')f1=true;
        if(x+1<W&&fld[y][x+1]=='#')f2=true;
        if(f1){
            vis[y+1][x]=true;
            y++;
        }
        else if(f2){
            vis[y][x+1]=true;
            x++;
        }
        else{
            break;
        }
    }

    rep(i,H){
        rep(j,W){
            if(fld[i][j]=='.')continue;
            if(!vis[i][j]){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}
