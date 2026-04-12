#include "bits/stdc++.h"

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF 999999999
int ans[11][11]={};

vector<vector<int> > d(int y,int x,vector<vector<int> > t){
    int dx[]={0,0,0,-1,1};
    int dy[]={-1,0,1,0,0};
    rep(k,5){
        int ddy=y+dy[k],ddx=x+dx[k];
        if(ddx>=0&&ddy>=0&&ddx<10&&ddy<10){
            t[ddy][ddx]=!t[ddy][ddx];
        }
    }
    return t;
}

int main(){
    int n;
    cin>>n;
    rep(loop,n){
        vector<vector<int> > data;
        rep(i,10){
            vector<int> a(10);
            rep(j,10)cin>>a[j];
            data.pb(a);
        }
//        rep(i,10){rep(j,10)cout<<data[i][j]<<" ";cout<<endl;}
        rep(i,1<<10){
            vector<vector<int> > t=data;
            rep(j,11)rep(k,11)ans[j][k]=0;
            rep(j,10){
                ans[0][j]=((i&(1<<j))!=0);
                if(ans[0][j])t=d(0,j,t);
            }
            for(int j=1;j<10;j++){
                for(int k=0;k<10;k++){
                    if(t[j-1][k]==1){
                        ans[j][k]=1;
                        t=d(j,k,t);
                    }
                }
            }
            bool f=true;
            rep(j,10){
                if(t[9][j]==1)f=false;
            }
            if(f){
                rep(j,10){
                    rep(k,10){
                        if(k)cout<<" ";
                        cout<<ans[j][k];
                    }
                    cout<<endl;
                }
                break;
            }
        }
    }
}