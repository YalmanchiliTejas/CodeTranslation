#include <bits/stdc++.h>
using namespace std;
int main(){
    int H,W;
    cin>>H>>W;
    char a[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>a[i][j];
        }
    }
    char checkrow[H];
    char checkcol[W];
    for(int i=0;i<H;i++){
        checkrow[i]=1;
    }
    for(int i=0;i<W;i++){
        checkcol[i]=1;
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(a[i][j]=='#'){break;}
            if(j==W-1){checkrow[i]=0;}
        }
    }
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            if(a[j][i]=='#'){break;}
            if(j==H-1){checkcol[i]=0;}
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(checkrow[i]==1&&checkcol[j]==1){cout<<a[i][j];}
        }
        if(checkrow[i]==1){puts("");}
    }
}