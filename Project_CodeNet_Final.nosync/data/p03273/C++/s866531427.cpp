#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main(void){
    int H,W;
    cin>>H>>W;
    char str[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>str[i][j];
        }
    }
    int line[H];
    int row[W];
    for(int i=0;i<H;i++){
        line[i]=0;
    }
    for(int j=0;j<W;j++){
        row[j]=0;
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(str[i][j]=='#') {
                line[i]=1;
                row[j]=1;
                }
                }
            }
    for(int i=0;i<H;i++){int ans=0;
        for(int j=0;j<W;j++){
            if(row[j]==1&&line[i]==1) {cout<<str[i][j]; ans=1;}
            if(j==W-1&&ans==1) cout<<endl;
        }
    }
    return 0;
}
