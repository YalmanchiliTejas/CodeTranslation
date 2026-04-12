#include<bits/stdc++.h>
using namespace std;



int main(void){
    int H,W;
    cin>>H>>W;
    vector<vector<char>>a(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>a[i][j];
        }
    }
    vector<bool> judge1(H,false);
    vector<bool> judge2(W,false);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(a[i][j]=='#') {
                judge1[i]=true;
                judge2[j]=true;
            }
        }
    }
    for(int i=0;i<H;i++){
        if(judge1[i]){
            for(int j=0;j<W;j++){
                if(judge2[j]){
                cout<<a[i][j];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

