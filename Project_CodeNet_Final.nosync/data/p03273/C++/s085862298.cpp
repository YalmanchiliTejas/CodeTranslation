#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    char square[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>square[i][j];
        }
    }
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<m;j++){
            if(square[i][j]=='#'){
                flag=false;
                break;
            }
        }
        if(flag){
            for(int j=0;j<m;j++){
                square[i][j]='!';
            }
        }
    }
    for(int i=0;i<m;i++){
        bool flag=true;
        for(int j=0;j<n;j++){
            if(square[j][i]=='!')continue;
            if(square[j][i]=='#'){
                flag=false;
                break;
            }
        }
        if(flag){
            for(int j=0;j<n;j++){
                square[j][i]='!';
            }
        }
    }
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<m;j++){
            if(square[i][j]!='!'){
                cout<<square[i][j];
                flag=false;
            }
        }
        if(flag==false)cout<<endl;
    }
    return 0;
}
