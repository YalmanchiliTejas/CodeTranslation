#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MX=10, inf=2e9;

int h,w;
char B[MX][MX];
bool vis[MX][MX];

bool valid(int x, int y){
    return 1<=x && x<=h && 1<=y && y<=w && B[x][y]=='#';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>h>>w;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            cin>>B[i][j];
    int x=1, y=1;
    while(true){
        B[x][y]='.';
        if(valid(x+1,y)){
            x++; continue;
        }
        if(valid(x,y+1)){
            y++; continue;
        }
        break;
    }
    bool yes=true;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            yes&=B[i][j]=='.';
    cout<<(yes?"Possible":"Impossible");
    return 0;
}