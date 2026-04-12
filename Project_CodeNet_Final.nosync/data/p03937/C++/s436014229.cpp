#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    char a[h][w];
    int flag[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
            flag[i][j] = 0;
        }
    }

    int ans = 0;
    int now_x = 0;
    int now_y = 0;
    while(1){
        if(now_x == h - 1 && now_y == w - 1){
            flag[now_x][now_y] = 1;
            break;
        }
        flag[now_x][now_y] = 1;
        if(a[now_x + 1][now_y] == '#'){
            now_x++;
        }else if(a[now_x][now_y + 1] == '#'){
            now_y++;
        }else{
            break;
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#' && flag[i][j] == 0){
                ans = 1;
                break;
            }
        }
    }

    if(ans == 1){
        cout << "Impossible" << endl;
    }else{
        cout << "Possible" << endl;
    }
}