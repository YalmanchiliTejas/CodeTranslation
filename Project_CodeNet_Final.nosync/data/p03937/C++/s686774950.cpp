#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#define INF 100000000
#define MOD 1000000007
using namespace std;


int main(){
    int H,W;
    cin>>H>>W;
    char A[H+1][W+1];
    for(int i=0; i<=H; i++){
        for(int j=0; j<=W; j++){
            if(i==H || j==W){
                A[i][j]=='.';
            }else{
                cin>>A[i][j];
            }
        }
    }
    
    A[H][W-1]='#';
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(A[i][j]=='#'){
                int ue=0;
                int hidari=0;
                if(i<=0 || A[i-1][j]=='#'){
                    ue=1;
                }
                if(j<=0 || A[i][j-1]=='#'){
                    hidari=1;
                }
                if(!(ue|hidari)){
                    cout<<"Impossible"<<endl;
                    return 0;
                }
                
                if(A[i+1][j]=='#' xor A[i][j+1]=='#'){
                    
                }else{
                    cout<<"Impossible"<<endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "Possible"<<endl;
    return 0;
}
