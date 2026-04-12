#include <bits/stdc++.h>
using namespace std;


int main (){
    int H, W;
    cin>>H>>W;
    vector<vector<char>> A(H, vector<char>(W));
    vector<vector<int>> B(H, vector<int>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>A.at(i).at(j);
            B.at(i).at(j)=(A.at(i).at(j)=='#'?1:0);
        }
    }
    for(int i=0; i<H; i++){
        int Sum=0;
        for(int j=0; j<W; j++){
            Sum += B.at(i).at(j);
        }
        if(Sum==0){
            for(int j=0; j<W; j++){
                A.at(i).at(j)='%';
            }
        }
    }
    for(int i=0; i<W; i++){
        int Sum=0;
        for(int j=0; j<H; j++){
            Sum += B.at(j).at(i);
        }
        if(Sum==0){
            for(int j=0; j<H; j++){
                A.at(j).at(i)='%';
            }
        }
    }

    for(int i=0; i<H; i++){
        bool Check=false;
        for(int j=0; j<W; j++){
            if(!(A.at(i).at(j)=='%')){
                cout<<A.at(i).at(j);
                Check=true;
            }
        }
        if(Check){
            cout<<endl;
        }
    }
    
}