#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    vector<bool> r(H);
    vector<bool> c(W);
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> A[i][j];
            if(A[i][j]=='#') r[i]=true;
            if(A[i][j]=='#') c[j]=true;
        }
    }
    
    for(int i=0; i<H; i++){
        if(r[i]){
            for(int j=0; j<W; j++){
                if(c[j]) cout << A[i][j];
            }
        cout << endl;
        }
    }
    return 0;
}
