#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    
    int H, W;
    cin >> H;
    cin >> W;

    vector<string> arr(H);
    for(int i = 0; i < H; i++){
        cin >> arr[i];
    }

    int checkLineH[H] = {0};
    int checkLineW[W] = {0};

    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            if(arr[h][w] == '#'){
                checkLineH[h] = 1;
                checkLineW[w] = 1;
            }
        }
    }


    for(int h = 0; h < H; h++){
        bool flag = false;
        for(int w = 0; w < W; w++){
            if(checkLineH[h] && checkLineW[w]){
                cout << arr[h][w];
                flag = true;
            }
        }
        if(flag) cout << endl;
    }

}

