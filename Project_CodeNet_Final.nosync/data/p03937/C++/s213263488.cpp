#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<set>
#include<map>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;

int main(){
    int h,w;
    char m[9][9];
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>m[i][j];
        }
    }
    bool v[9][9];
    memset(v, 0, sizeof(v));
    int x=0,y=0;
    while(1){
        v[y][x]=1;
        if(x<w-1&&m[y][x+1]=='#'){
            x++;
            continue;
        }
        if(y<h-1&&m[y+1][x]=='#'){
            y++;
            continue;
        }
        break;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(m[i][j]=='#'&&v[i][j]==0){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}