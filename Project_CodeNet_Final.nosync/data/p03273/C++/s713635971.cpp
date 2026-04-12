#include <iostream>
#include<vector>
using namespace std;

int main(){
    int H,W;
    vector<vector<char>> A;
    cin >> H >> W;
    A.resize(H);
    for(int i=0;i<H;i++){
        A[i].resize(W);
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j]; 
        }
    }
    for(int i=0;i<A.size();i++){
        if(A[i][0]!='#'){
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]=='#'){
                    break;
                }
                if(j==A[i].size()-1){
                    for(int k=0;k<A[i].size();k++){
                        A[i][k]='B';
                    }
                }
            }
        }
    }
    for(int j=0;j<A[0].size();j++){
        if(A[0][j]!='#'){
            for(int i=0;i<A.size();i++){
                if(A[i][j]=='#'){
                    break;
                }
                if(i==A.size()-1){
                    for(int k=0;k<A.size();k++){
                        A[k][j]='B';
                    }
                }
            }
        }
    }
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if(A[i][j]!='B'){
                cout << A[i][j];
            }
        }
        cout <<"\n";
    }
}