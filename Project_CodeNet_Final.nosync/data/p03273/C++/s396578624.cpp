#include <iostream>
#include <string>

using namespace std;

#define ll long long

int H, W;
string FD[105];
string buff;
bool isNotWhiteRow[105] = {0}, isNotWhiteCol[105] = {0};

int main(){
    cin >> H >> W;

    for(int i = 0; i < H; i++){
        cin >> buff;
        FD[i] = buff;
        for(int j = 0; j < W; j++){
            if(buff[j]=='#') {
                isNotWhiteRow[i] = true;
                isNotWhiteCol[j] = true;
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(isNotWhiteRow[i] && isNotWhiteCol[j]) {
                cout << FD[i][j];
            }
        }
        if(isNotWhiteRow[i]) cout << endl;
    }
}
