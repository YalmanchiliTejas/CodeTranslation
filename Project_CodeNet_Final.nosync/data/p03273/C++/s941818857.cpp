#include <bits/stdc++.h>
using namespace std;
//関数
const long INF=1000000000000000;

int main(void){
    long H,W;
    cin>>H>>W;
    
    vector<vector<char>> a(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>a.at(i).at(j);
        }
    }
    
    vector<bool> remh(H,true),remw(W,true);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(a.at(i).at(j)=='#'){
                remh.at(i)=false;
                remw.at(j)=false;
            }
        }
    }
    
    for(int i=0;i<H;i++){
        if(remh.at(i)) continue;
        for(int j=0;j<W;j++){
            if(!remw.at(j)) cout<<a.at(i).at(j);
        }
        cout<<endl;
    }
    
}

