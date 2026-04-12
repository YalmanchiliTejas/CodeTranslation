#include<bits/stdc++.h>
using namespace std;
char c[105][105];
int y[105];
int x[105];
int main(){
    int h,w;
    cin >> h >> w;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin >> c[i][j];
    int flag=0;
    int rm=0;
    for(int i=0;i<h;i++){
        flag=0;
        for(int j=0;j<w;j++)if(c[i][j]=='.')flag++;
        if(flag==w)y[i]++;
    }
    for(int i=0;i<w;i++){
        flag=0;
        for(int j=0;j<h;j++)if(c[j][i]=='.')flag++;
        if(flag==h)x[i]++;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)if(y[i]==0 && x[j]==0)cout << c[i][j];
        if(y[i]==0)cout << endl;
    }
}