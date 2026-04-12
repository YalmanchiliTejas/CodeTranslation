#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

typedef long long ll;

int main(){
    int n;
    cin >> n;
    while(n!=0){
        int bs[10][10]; 
        REP(i,10)REP(j,10)cin >> bs[i][j];
        int flip[10][10]; 
        int ans[10][10]; 
        REP(i,1<<10){
            memset(flip,0,sizeof(flip));
            memset(ans,0,sizeof(ans));
            REP(j,10){
                if((i>>j)&1){
                    ans[0][j]=1;
                    flip[0][j]^=1;
                    if(j-1>=0)flip[0][j-1]^=1;
                    if(j+1<10)flip[0][j+1]^=1;
                    flip[1][j]^=1;
                }
            }
            FOR(y,1,10){
                REP(x,10){
                    if(flip[y-1][x] ^ bs[y-1][x]){
                        ans[y][x]=1;
                        flip[y-1][x]^=1;
                        flip[y][x]^=1;
                        if(x-1>=0)
                            flip[y][x-1]^=1;
                        if(x+1<10)
                            flip[y][x+1]^=1;
                        if(y+1<10)
                            flip[y+1][x]^=1;
                    }
                }
            }

            int flag=1;
            REP(y,10){
                REP(x,10){
                    if(flip[y][x] ^ bs[y][x]){
                        flag=0;
                        y=10;
                        break;
                    }
                }
            }

            if(flag){
                REP(y,10){
                    REP(x,10){
                        cout << ans[y][x]  << (x==9 ? "\n" : " ");
                    }
                }
                break;
            }
        }
        n--;
    }
    return 0;
}