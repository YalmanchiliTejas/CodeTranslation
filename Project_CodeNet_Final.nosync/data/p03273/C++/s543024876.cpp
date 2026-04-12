#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    char c[n][m];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            cin>>c[i][j];
    }
    
    int h[n]={0}, w[m]={0};
    
    for(int i=0; i<n; ++i){
        int j=0;
        while(c[i][j]=='.' and j<m) j++;
        if(j==m) h[i]=1;
    }
    
    for(int i=0; i<m; ++i){
        int j=0; 
        while(c[j][i]=='.' and j<n) j++;
        if(j==n) w[i]=1;
    }
    
    for(int i=0; i<n; ++i){
        bool check=true;
        for(int j=0; j<m; ++j){
            if(!h[i] and !w[j]){
                cout<<c[i][j];
                check=false;
            }
        }
        if(!check)
            cout<<endl;
    }
    
    return 0;
}