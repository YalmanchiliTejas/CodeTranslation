#include<bits/stdc++.h>
using namespace std;
string grid[101];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>grid[i];
    for(int i=0;i<n;i++){
        int all=1;
        for(int j=0;j<m;j++)
            if(grid[i][j]!='.'){
                all=0;
                break;
            }
        if(all){
            for(int j=i+1;j<n;j++)
                grid[j-1]=grid[j];
            i--,n--;
        }
    }
    for(int i=0;i<m;i++){
        int all=1;
        for(int j=0;j<n;j++)
            if(grid[j][i]!='.'){
                all=0;
                break;
            }
        if(all){
            for(int j=i+1;j<m;j++)
                for(int k=0;k<n;k++)
                    grid[k][j-1]=grid[k][j];
            i--,m--;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            putchar(grid[i][j]);
        puts("");
    }
    return 0;
}