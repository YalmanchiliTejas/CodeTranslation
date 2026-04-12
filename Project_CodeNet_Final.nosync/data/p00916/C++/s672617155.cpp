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

ll mask[111][111];
int col[111][111];
typedef pair<int,int> P;

inline bool valid(int x, int y){
    return 0 <= x && x < 111 && 0 <= y && y < 111;
}

int solve(){
    vi xs, ys;
    rep(i,n){
        xs.push_back(x[i]);
        xs.push_back(xx[i]);
        ys.push_back(y[i]);
        ys.push_back(yy[i]);
    }
    xs.push_back(-1);
    ys.push_back(-1);
    sort(all(xs));
    sort(all(ys));
    xs.erase(unique(all(xs)), xs.end());
    ys.erase(unique(all(ys)), ys.end());

    memset(mask,0,sizeof(mask));
    rep(i,n){
        int x1=lower_bound(all(xs), x[i])-xs.begin();
        int x2=lower_bound(all(xs), xx[i])-xs.begin();
        int y1=lower_bound(all(ys), y[i])-ys.begin();
        int y2=lower_bound(all(ys), yy[i])-ys.begin();
        // printf("%d %d ", x1,x2);
        // printf("%d %d\n", y1,y2);
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
    rep(i,111)rep(j,111)if(col[i][j]==0){
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
        // for(int i=ys.size();i>=0;i--){
        //     rep(j,xs.size()+1){
        //         cout << col[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // puts("-");
    }
    return cnt;
}

int main(){
    int cnt = 0;
    while(cin>>n && n){
        cnt++;
        rep(i,n)cin>>x[i]>>y[i]>>xx[i]>>yy[i];
        if(cnt==18){
            auto fp = fopen("badcase.txt","w");
            fprintf(fp,"%d\n",n);
            rep(i,n){
                fprintf(fp,"%d %d %d %d\n", x[i],y[i],xx[i],yy[i]);
            }
        }
        cout << solve() << endl;
    }
}