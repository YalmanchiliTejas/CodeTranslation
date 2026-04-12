#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int h,w;
    char a[100][100];
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    int b;
    for(int i=0;i<h;i++){
        b=0;
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                b=1;
                break;
            }
        }
        if(b==0){
            for(int j=i+1;j<h;j++){
                for(int k=0;k<w;k++){
                    a[j-1][k]=a[j][k];
                }
            }
            h--;
            i--;
        }
    }
    for(int i=0;i<w;i++){
        b=0;
        for(int j=0;j<h;j++){
            if(a[j][i]=='#'){
                b=1;
                break;
            }
        }
        if(b==0){
            for(int j=i+1;j<w;j++){
                for(int k=0;k<h;k++){
                    a[k][j-1]=a[k][j];
                }
            }
            w--;
            i--;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}