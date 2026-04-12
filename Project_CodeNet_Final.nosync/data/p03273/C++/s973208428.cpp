#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
using namespace std;
 
int main(){
    
    int H,W,y=0,x=0;
    char A[100][100]={},B[100][100]={},C[100][100];
    bool f=0;

    cin >> H >>W;

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j];
        }
    }

    for(int i=0;i<H;i++){
        f=0;
        for(int j=0;j<W;j++){
            if(A[i][j]=='#'){
                f=1;
                
            }
        }
        if(f==1){
            for(int k=0;k<W;k++){
                B[y][k]=A[i][k];
            }
            y+=1;
        }
    }


    for(int i=0;i<W;i++){
        f=0;
        for(int j=0;j<y;j++){
            if(B[j][i]=='#'){
                f=1;
            }
        }

        if(f==1){
            for(int k=0;k<y;k++){
                C[k][x]=B[k][i];
            }
            x+=1;
        }
    }


    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cout << C[i][j];
        }
        cout <<endl;
    }



    return 0;

}