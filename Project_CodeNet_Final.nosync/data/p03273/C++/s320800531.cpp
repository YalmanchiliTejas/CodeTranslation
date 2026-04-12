#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here
    int h,w;
    cin>>h>>w;
    map<int,int> P1,P2;
    char maze[h][w];
    for(int i=0;i<h;i++){
        string s;
        cin>>s;
        for(int j=0;j<w;j++){
            maze[i][j]=s[j];
            if(maze[i][j]=='#'){
                P1[i]=1;
                P2[j]=1;
            }
        }
    }
    for(int i=0;i<h;i++){
        int rec=0;
        for(int j=0;j<w;j++){
            if(P1[i]==0 || P2[j]==0){rec++;continue;}
            cout<<maze[i][j];
        }
        if(rec!=w)cout<<endl;
    }
}