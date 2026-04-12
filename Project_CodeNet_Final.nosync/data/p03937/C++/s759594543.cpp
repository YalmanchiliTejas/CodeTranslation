#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 8
char M[MAXN+5][MAXN+5];
int cnt,x=1,y=1;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=1;j<=m;j++){
            cin>>M[i][j];
            if(M[i][j]=='#') cnt++;
        }
    }
    for(int i=1;i<cnt;i++){
        if(M[x+1][y]=='#') x++;
        else if(M[x][y+1]=='#') y++;
        else {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}