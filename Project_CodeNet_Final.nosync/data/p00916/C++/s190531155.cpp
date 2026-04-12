#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(c) (c).begin(), (c).end()
#define loop(i,a,b) for(ll i=a; i<ll(b); i++)
#define rep(i,b) loop(i,0,b)
#ifdef DEBUG
#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<(DUMP(),__VA_ARGS__).str()<<" ["<<__LINE__<<"]"<<endl)
struct DUMP:ostringstream{template<class T>DUMP &operator,(const T&t){if(this->tellp())*this<<", ";*this<<t;return *this;}};
#else
#define dump(...)
#endif

int n;
int x[55],y[55],xx[55],yy[55];

ll mask[102][102];
int col[102][102];
typedef pair<int,int> P;

inline bool valid(int x, int y){
    return 0 <= x && x < 102 && 0 <= y && y < 102;
}

int xs[102], ys[102];

int solve(){
    int cx=0, cy=0;
    rep(i,n){
        xs[cx++]=x[i];
        xs[cx++]=xx[i];
        ys[cy++]=y[i];
        ys[cy++]=yy[i];
    }
    xs[cx++]=-1;
    ys[cy++]=-1;
    sort(xs,xs+cx);
    sort(ys,ys+cy);
    cx = unique(xs,xs+cx)-xs, cy = unique(ys,ys+cy)-ys;

    memset(mask,0,sizeof(mask));
    rep(i,n){
        int x1=lower_bound(xs,xs+cx,x[i])-xs;
        int x2=lower_bound(xs,xs+cx,xx[i])-xs;
        int y1=lower_bound(ys,ys+cy,y[i])-ys;
        int y2=lower_bound(ys,ys+cy,yy[i])-ys;
        loop(x,x1,x2){
            loop(y,y2,y1){
                mask[y][x]|=1LL<<i;
            }
        }
    }

    int cnt = 0;
    memset(col,0,sizeof(col));
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    rep(i,102)rep(j,102)if(col[i][j]==0){
        cnt++;
        stack<P> s; s.push(P(j,i));
        while(s.size()){
            int x,y;
            tie(x,y) = s.top(); s.pop();
            if(col[y][x]) continue;
            col[y][x] = cnt;
            rep(d,4){
                int nx,ny;
                tie(nx,ny) = P(x+dx[d], y+dy[d]);
                if(!valid(nx,ny)) continue;
                if(mask[y][x]!=mask[ny][nx]) continue;
                if(col[ny][nx]) continue;
                s.push(P(nx,ny));
            }
        }
    }
    return cnt;
}

int main(){
    int cnt = 0;
    while(cin>>n && n){
        cnt++;
        rep(i,n)cin>>x[i]>>y[i]>>xx[i]>>yy[i];
        cout << solve() << endl;
    }
}