#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void){
    int h,w;
    cin >> h >> w;
    char grid[h+1][w+1];
    int n[h],m[w];
    int flag;
    for(int i=0; i<h; i++){
        n[i]=1;
        flag=0;
        for(int j=0; j<w; j++){
            cin >> grid[i][j];
            if(grid[i][j]=='#')flag=1;
        }
        if(flag!=1)n[i]=0;
    }
    for(int i=0; i<w; i++){
        flag=0;
        m[i]=1;
        for(int j=0; j<h; j++){
            if(grid[j][i]=='#')flag=1;
        }
        if(flag!=1)m[i]=0;
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(n[i]&&m[j]){
                cout << grid[i][j];
            }
        }
        if(n[i])cout << endl;
    }
    return 0;
}