#include<bits/stdc++.h>
using namespace std;

const int dx[]={-1,0,1,0,0};
const int dy[]={0,-1,0,1,0};

int ans[10][10];
int latte[10][10];

void change(int y,int x){
    for(int d=0;d<5;d++){
        int ty=y+dy[d],tx=x+dx[d];
        if(ty<0||ty>=10||tx<0||tx>=10)continue;
        latte[ty][tx]=1-latte[ty][tx];
    }
}

void solve(){
    int fld[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>fld[i][j];
        }
    }

    for(int s=0;s<(1<<11);s++){
        fill_n(*ans,100,0);

        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                latte[i][j]=fld[i][j];

        for(int i=0;i<10;i++){
            if((s>>i)&1){
                ans[0][i]=1;
                change(0,i);
            }
        }

        for(int i=1;i<10;i++){
            for(int j=0;j<10;j++){
                if(latte[i-1][j]){
                    ans[i][j]=1;
                    change(i,j);
                }
            }
        }

        bool f=true;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(latte[i][j])f=false;
            }
        }

        if(f){
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    if(j)cout<<" ";
                    cout<<ans[i][j];
                }
                cout<<endl;
            }
            return;
        }
    }
}

int main(){
    int N;
    cin>>N;
    while(N--)solve();
    return 0;
}