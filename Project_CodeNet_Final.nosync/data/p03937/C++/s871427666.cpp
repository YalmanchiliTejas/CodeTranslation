#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    char c[h][w];
    int ta=0;
    rep(i,h)rep(j,w){
        cin>>c[i][j];
        if(c[i][j]=='#')ta++;
    }
    queue<pair<int,int>> que;que.push({0,0});
    ta--;
    int roty[2]={1,0},rotx[2]={0,1};
    while(que.size()){
        int y=que.front().first,x=que.front().second;que.pop();
        if(y==h-1&&x==w-1)break;
        rep(i,2){
            int ny=y+roty[i],nx=x+rotx[i];
            if(ny<0||ny>=h||nx<0||nx>=w)continue;
            if(c[ny][nx]!='#')continue;
            c[ny][nx]='.';
            ta--;
            que.push({ny,nx});break;
        }
    }
    if(ta!=0)cout<<"Impossible"<<endl;
    else cout<<"Possible"<<endl;
}