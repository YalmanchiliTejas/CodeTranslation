#include <bits//stdc++.h>
using namespace std;
int main(void){
    int H,W;
    cin >>H>>W;
    vector<vector<char>>data(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> data[i][j];
        }
    }
    vector<vector<char>>A(H,vector<char>(W,'-'));
    vector<vector<char>>B(H,vector<char>(W,'-'));
    int r=0;
    //縦消し
    for(int i=0;i<H;i++){
        bool erase = true;
        for(int j=0;j<W;j++){
            if(data[i][j]=='#'){
                erase = false;
            }
        }
        if(erase==false){
            for(int j=0;j<W;j++){
                A[r][j]=data[i][j];
                }
            r++;
        }
    }
    //横消し
    int s=0;
    for(int j=0;j<W;j++){
        bool erase = true;
        for(int i=0;i<H;i++){
            if(A[i][j]=='#'){
                erase = false;
            }
        }
        if(erase==false){
            for(int i=0;i<H;i++){
                B[i][s]=A[i][j];
                }
            s++;
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(B[i][j]!='-'){
                cout << B[i][j];
                if(j==W-1 || B[i][j+1]=='-'){
                    cout <<endl;
                }
                
            
            }
        }
    }
}
