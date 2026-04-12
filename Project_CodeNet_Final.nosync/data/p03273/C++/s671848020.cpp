#include<iostream>
#include<string>
using namespace std;

int main(void){

    int H,W;
    cin>>H>>W;

    int A[W],B[H];
    for(int i=0;i<W;i++){
        A[i]=1;
    }

    string C[H];
    for(int i=0;i<H;i++){
        B[i]=1;
        cin>>C[i];

    }
    
    for (int w=0; w<W; w++) {
        for (int h=0; h<H; h++) {
            if (C[h][w] == '#') {
                A[w] = 0;
                break;
            }
        }
    }

    for (int h=0; h<H; h++) {
        for (int w=0; w<W; w++) {
            if (C[h][w] == '#') {
                B[h] = 0;
                break;
            }
        }
    }
    
    for (int h=0; h<H; h++) {
        for (int w=0; w<W; w++) {
            if (A[w] == 0 && B[h] == 0) {
                cout << C[h][w];
            }
        }
        if (B[h] == 0) {
            cout << endl;
        }
    }
    
  

    // for (int i=0;i<H;i++){  
       

    //     int N=0;
    //     for(int j=0;j<W;j++){
            
    //         if(C[i][j]=='.'){
    //             N=N+1;
    //             A[j]=A[j]+1;
    //         }
    //     }
    //     if(N==W){
    //         B[i]=1;
    //     }
        
    // }
    
    // for(int i=0;i<H;i++){

    //     if(B[i]==0){
    //         int outputted = 0;
    //         for(int j=0;j<W;j++){
    //             if(A[j]!=W){
    //                 cout<<C[i][j];
    //                 outputted = 1;
    //             }
    //         }
    //         if (outputted  > 0) {
    //             cout << endl;
    //         }

    //     }
    // }
    // cout<<endl;

    return 0;
}