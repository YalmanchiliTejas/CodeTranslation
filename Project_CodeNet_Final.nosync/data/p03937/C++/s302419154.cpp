//C++14 (Clang 3.8.0)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#define rp(i,a,b) for(int (i)=(int)(a);i<(int)(b);++i)
using namespace std;
typedef pair<int,int> P;
char a[10][10];
int X,Y;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool flag=true;
bool dfs(int x,int y){
    a[x][y]='.';
    rp(i,0,2){
        int nx=x+dx[i],ny=y+dy[i];
        if(0<=nx and nx<X and 0<=ny and ny<Y and a[nx][ny]=='#'){
            return dfs(nx,ny);

        }
    }
    return false;
    /*
    rp(i,2,4){
        int nx=x+dx[i],ny=y+dy[i];
        if(0<=nx and nx<X and 0<=ny and ny<Y and a[nx][ny]=='#'){
            flag=false;

        }
    }
    */
        
}
int main(){
    cin>>Y>>X;
    rp(i,0,Y){rp(j,0,X) cin>>a[j][i];};
    //rp(i,0,Y){rp(j,0,X) cout<<a[j][i];cout<<endl;};
    dfs(0,0);
    rp(i,0,Y){
        rp(j,0,X){if(a[j][i]=='#')flag=false;
        } 
    };
    if(flag)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
};
