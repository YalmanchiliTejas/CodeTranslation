#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;
char maze[10][10];



int main(){

    int h,w;
    cin>>h>>w;
    
    int cnt=0;
    rep(i,h)rep(k,w){cin>>maze[i][k];
    if(maze[i][k]=='#')cnt++;
    }
    /*
    queue<int>q;
    int dx[2]={0,1};
    int dy[2]={1,0};

    q.push(0);
    q.push(0);
    bool ans=(maze[0][0]=='#');

    while(!q.empty()){
    
        int nowx=q.front();q.pop();
        int nowy=q.front();q.pop();

        if(nowx==w-1 && nowy==h-1)break;

        int cnt=0;

        rep(i,2){
            int nx=nowx+dx[i];
            int ny=nowy+dy[i];

            if(nx>=w||ny>=h)continue;

            if(maze[ny][nx]=='#'){
            cnt++;
            q.push(nx);
            q.push(ny);
            }
        }

        if(cnt!=1){
        ans=false;
        break;
        }
    }

    */
   bool ans=(cnt ==h+w-1);
    if(ans){
        cout<<"Possible"<<endl;
    }
    else{
        cout<<"Impossible"<<endl;
    }

    return 0;

}
/*
2 2
.#
.#

*/
