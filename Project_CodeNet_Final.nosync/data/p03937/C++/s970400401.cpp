#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[]={1,0};
int dy[]={0,1};

int main(){
    int h,w;
    cin>>h>>w;
    vector<string> a(h);
    for(int i=0;i<h;i++) cin>>a[i];
    queue<pair<int,int>> q;
    if(a[0][0]=='#'){
        q.push(make_pair(0,0));
        a[0][0]='.';
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<2;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=w||ny>=h||a[ny][nx]=='.') continue;
            a[ny][nx]='.';
            q.push(make_pair(nx,ny));
            break;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
}