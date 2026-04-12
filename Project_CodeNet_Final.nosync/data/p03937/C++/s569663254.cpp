#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
#define max_n 100
#define INF 100000000

int h,w;
char a[8][9];

void dfs(int x,int y){
    a[x][y]='.';
    if(x==h-1&&y==w-1){
        return ;
    }
    if(a[x][y+1]=='#'){
        dfs(x,y+1);
    }else if(a[x+1][y]=='#'){
        dfs(x+1,y);
    }else{
        return ;
    }
}

int main()
{
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    dfs(0,0);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
            
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}
