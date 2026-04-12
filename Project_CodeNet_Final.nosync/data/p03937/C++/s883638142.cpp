#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

int H, W;
char map[8][8];

int check(int h, int w){
    
    //cout << h << ":" << w << endl;
    map[h][w] = '.';

    if(h == H - 1 && w == W - 1){
        for(int h = 0; h < H; h++){
            for(int w = 0; w < W; w++){
                if(map[h][w] == '#'){
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
        cout << "Possible" << endl;
        return 0;
    }

    int cnt = 0;
    if(h + 1 < H){
        if(map[h+1][w] == '#'){
            cnt += 1;
        }
    }
    if(w + 1 < W){
        if(map[h][w+1] == '#'){
            cnt += 2;
        }
    }

    if(cnt == 0 || cnt == 3){
        cout << "Impossible" << endl;
        return 0;
    }
    
    if(cnt == 1){
        check(h+1, w);
    }
    if(cnt == 2){
        check(h, w+1);
    }

    return 0;

}

int main(){

    cin >> H >> W;

    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            cin >> map[h][w];
        }
    }
    check(0,0);

}