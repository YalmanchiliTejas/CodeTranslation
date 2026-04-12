#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int H,W;
    cin>>H>>W;
    char S[H+2][W+2];
    for(int i=0;i<H+2;i++){
        for(int j=0;j<W+2;j++){
            if(i!=H+1&&j!=W+1&&i!=0&&j!=0){
                cin>>S[i][j];
            }
            else S[i][j]='.';
        }
    }
    S[H][W+1]='#';
    S[1][0]='W';
    bool check=true;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i+1][j+1]=='#'){
                if(S[i+2][j+1]==S[i+1][j+2]) check=false;
                if(S[i][j+1]==S[i+1][j]) check=false;
            }
        }
    }
    if(check) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
