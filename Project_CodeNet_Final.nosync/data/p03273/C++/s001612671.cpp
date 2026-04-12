#include<iostream>
using namespace std;

int H,W;
char F[110][110];
int del[110][110];

int main(){
    cin >> H >> W;
    for(int i=1;i<=H;i++) for(int j=1;j<=W;j++) cin >> F[i][j];
    for(int i=1;i<=H;i++){
        bool ok = true;
        for(int j=1;j<=W;j++) if(F[i][j]=='#') ok = false;
        if(ok) for(int j=1;j<=W;j++) del[i][j] = 1;
    }
    for(int j=1;j<=W;j++){
        bool ok = true;
        for(int i=1;i<=H;i++) if(F[i][j]=='#') ok = false;
        if(ok) for(int i=1;i<=H;i++) del[i][j] = 1;
    }
    for(int i=1;i<=H;i++){
        bool printed = false;
        for(int j=1;j<=W;j++) if(!del[i][j]){
            cout << F[i][j]; printed = true;
        }
        if(printed) cout << endl;
    }
}