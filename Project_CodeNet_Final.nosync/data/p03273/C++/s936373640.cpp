#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <queue>
using namespace std;
using ll=long long;
//using R=double;

const int INF = 10000000;
typedef pair<int, int> p;

int main(){

    int H,W;
    cin >> H >> W;
    string a[H];
    for(int i = 0; i < H; i++){
        cin >> a[i];
    }

    vector<int> tate_eraser;
    vector<int> yoko_eraser;

    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            if(a[j][i] == '#'){
                break;
            }
            if(j == H-1){
                tate_eraser.push_back(i);
                //cout << "tate : " << i << endl;
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(a[i][j] == '#'){
                break;
            }
            if(j == W-1){
                yoko_eraser.push_back(i);
                //cout << "yoko : " << i << endl;
            }
        }
    }


    string gyou_result = ""; 

    for(int i = 0; i < H; i++){
        //cout << i << endl;
        if(find(yoko_eraser.begin(), yoko_eraser.end(),i) != yoko_eraser.end()){
            continue;
        }
        for(int j = 0; j < W; j++){
            if(find(tate_eraser.begin(), tate_eraser.end(),j) != tate_eraser.end()){
            continue;
            }
            gyou_result += a[i][j];
        }
        cout << gyou_result << endl;
        gyou_result = "";
    }

    return 0;

}
