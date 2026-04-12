#include <bits/stdc++.h>
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define setDP(arr) memset(arr,-1,sizeof arr)
#define Clear(arr) memset(arr,0,sizeof arr)
#define oo 2000000000
#define inf 1000000000000000000
#define P1 31
#define P2 37
#define M  1000000007
#define M2 1000000009
#define pii pair<ll,ll>
typedef long long ll;
using namespace std;
const int N = 255001;
const int SQRTN = 320;
const int LOGN = 20;
const long double PI = acos(-1);
const long double TAU = 2*PI;

int h,w,cc;
char g[22][22];

bool gn(int ctr,int x, int y){
    if(g[x][y]=='#')ctr--;
    if(ctr==0)return 1;
    if(x<h-1)if(gn(ctr,x+1,y))return 1;
    if(y<w-1)if(gn(ctr,x,y+1))return 1;
    return 0;
}

signed main(){
    cin >> h >> w;
    for(int i = 0 ; i < h ; i++){
        scanf(" %s", g[i]);
        for(int j = 0 ; j < w ; j++){
            cc+=(g[i][j]=='#');
        }
    }
    if(gn(cc,0,0))return puts("Possible"),0;
    puts("Impossible");




}
