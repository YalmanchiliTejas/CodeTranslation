#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, i, j;
    vector <string> str(100);
    vector <int> e_pos;
    int cnt = 0, cnt_i = -1;
    vector <int> Hi, Wj;

    cin >> H >> W;
    for(i = 0; i < H; i++){
        cin >> str[i];
        for(j = 0; j < W; j++){
            if(str[i][j] == '.'){
                cnt++;
            }
            if(j == W - 1){
                Hi.push_back(cnt);
                cnt = 0;
            }
        }
    }
    for(j = 0; j < W; j++){
        for(i = 0; i < H; i++){
            if(str[i][j] == '.'){
                cnt++;
            }
            if(i == H - 1){
                Wj.push_back(cnt);
                cnt = 0;
            }
        }
    }
    for(i = 0; i < H; i++){
        if(Hi[i] == W){
            continue;
        }
        for(j = 0; j < W; j++){
            if(Wj[j] == H){
                continue;
            }
            printf("%c", str[i][j]);
        }
        printf("\n");
    }

    return 0;
}
