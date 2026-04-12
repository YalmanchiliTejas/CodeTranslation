#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>

using namespace std;

/*迷路
const int INF = 50;

typedef pair<int,int> P;
char field[52][52];
int d[51][51];
int r,c;
int sx,sy;
int gx,gy;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int bfs(){
    queue<P> que;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            d[i+1][j+1] = INF;
        }
    }
    que.push(P(sy,sx));
    d[sy][sx]=0;
while(que.size()){
    P p=que.front();
    que.pop();
    if(p.second==gx&&p.first==gy) break;
    for(int i=0;i<4;i++){
        int nx=p.second+dx[i];
        int ny=p.first+dy[i];

        if(1<=nx&&nx<=c&&1<=ny&&ny<=r&&field[ny][nx]!='#'&&d[ny][nx]==INF){
            que.push(P(ny,nx));
            d[ny][nx] = d[p.first][p.second] + 1;
        }
    }
}
return d[gy][gx];
}
*/
int main(){
    int n;
    cin>>n;
    int h[n];
    int sum = 0;
    for(int i = 0; i<n;i++){
        cin >> h[i];
        int flag=0;
        for(int j = 0;j<=i;j++){
            if(h[j]>h[i]){
                flag=1;
                break;
            }
        }
        if(flag ==0){
            sum++;
        }
    }
    cout << sum << '\n';
    return 0;  
}