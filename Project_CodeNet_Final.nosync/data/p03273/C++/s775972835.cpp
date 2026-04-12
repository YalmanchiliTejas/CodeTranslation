#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int H, W, count = 0;
    string tmp;
    cin >> H >> W;
    vector<string> masu(H);
    vector<string> table(H);
    for(int i = 0; i < H; i++){
       cin >> tmp;
       masu[i] = tmp;
       masu[i] += "\n";
       table[i] = string(W+1,'T');
    }


    for(int i = 0; i < H; i++){
        bool flag = true;
        for(int j = 0; j < W; j++){
            if(masu[i][j] == '#'){
                flag = false;
            }
        }
        if(flag == true){
            for(int k = 0; k < W+1; k++){
                table[i][k] = 'F';
            }
        }
    }

    for(int i = 0; i < W; i++){
        bool flag = true;
        for(int j = 0; j < H; j++){
            if(masu[j][i] == '#'){
                flag = false;
            }
        }
        if(flag == true){
            for(int k = 0; k < H; k++){
                for(int k = 0; k < H; k++){
                    table[k][i] = 'F';
                }
            }
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W+1; j++){
            if(table[i][j] == 'T'){
                cout << masu[i][j];
            }
        }
    }

    return 0;
}