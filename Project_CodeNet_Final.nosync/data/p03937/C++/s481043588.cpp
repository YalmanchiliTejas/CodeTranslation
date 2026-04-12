#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int H,W,sharp=0;
    cin >> H >> W;
    vector<string> A(H);
    for(int i=0;i<H;i++){
        cin >> A[i];
    }
 
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(A[i][j]=='#'){
                    sharp++;
            }
        }
    }
 
    if(sharp == H+W-1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
}