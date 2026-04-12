#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define loop(i,a,b) for(int i=a; i<b; i++)
#define rep(i,b) loop(i,0,b)

int main(){
    int n;
    int g[15][15];
    while(cin>>n){
        if(n==0) break;
        memset(g,0,sizeof(g));
        int x=n/2, y=n/2+1;
        rep(i,n*n){
            g[y][x]=i+1;
            y=(n+y+1)%n;
            x=(n+x+1)%n;
            if(g[y][x]){
                y=(n+y+1)%n;
                x=(n+x-1)%n;
            }
        }
        rep(i,n){
            rep(j,n)
                printf("%4d",g[i][j]);
            puts("");
        }
    }
}