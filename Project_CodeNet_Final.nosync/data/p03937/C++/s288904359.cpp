#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main(){
    int H, W; 
    cin >> H >> W;
    vector<string> A(H);
    for(int i = 0; i < H; ++i){
        cin >> A[i];
    }
    int sum = 0;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(A[i][j] == '#'){
                sum++;
            }
        }
    }
    
    if(sum == H + W - 1){
        cout << "Possible\n";
    }
    else{
        cout << "Impossible\n";
    }
}