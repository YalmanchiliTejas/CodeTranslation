#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>

using namespace std;
typedef long long ll;

int gcd(int x, int y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    int r = x % y;
    x = y;
    y = r;
  }
  return x;
}

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
    int h,w;
    cin>>h>>w;
    char a[h][w];
    bool ho[h];
    bool wi[w];

    for(int i = 0; i<h; i++){
        ho[i]=true;
    }

    for(int i = 0; i<w; i++){
        wi[i]=true;
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin>>a[i][j];
            if(a[i][j]=='#') ho[i]=false;
        }
    }

     for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            if(a[j][i]=='#') wi[i]=false;
        }
     }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(ho[i]!=0||wi[j]!=0) ;
                else{
                    cout<<a[i][j];
                }
        }
        if(ho[i]==0)
        cout<<endl;
    }


    return 0;
}