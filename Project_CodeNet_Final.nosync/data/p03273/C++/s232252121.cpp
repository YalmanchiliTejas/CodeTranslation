#include<bits/stdc++.h>
using namespace std;
bool tate[101]={};
bool yoko[101]={};
int main(){
    int h, w;
    cin >> h >> w;
    char a[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
        }
    }
    
    for(int i=0;i<h;i++){
        int count=0;
        for(int j=0;j<w;j++){
            if(a[i][j]=='.') count++;
        }
        if(count==w) yoko[i]=true;
    }
    for(int j=0;j<w;j++){
        int count=0;
        for(int i=0;i<h;i++){
            if(a[i][j]=='.') count++;
        }
        if(count==h) tate[j]=true;
    }
    bool pre=false;
    for(int i=0;i<h;i++){
        if(!yoko[i]){
            for(int j=0;j<w;j++){
                if(!tate[j]){
                        cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}