#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#') break;
            if(j==w-1){
                for(int k=0;k<w;k++){
                    a[i][k]='n';
                }
            }
        }
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(a[j][i]=='#') break;
            if(j==h-1){
                for(int k=0;k<h;k++){
                    a[k][i]='n';
                }
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]!='n'){
                cout << a[i][j];
            }
        }
        cout << endl;
    }

}