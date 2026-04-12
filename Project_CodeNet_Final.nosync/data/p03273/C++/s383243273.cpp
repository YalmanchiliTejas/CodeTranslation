#include <iostream>
using namespace std;

int H,W;
char a[107][107];

int sx,sy;

void remove_x(int num){
//    cout << "横列消去: " << num << endl;
    for(int y = num;y < sy;y++){
        
        for(int x = 1;x < sx+1;x++){
            a[x][y] = a[x][y+1];
        }

    }

    for(int x = 1;x < sx+1;x++){
        a[x][sy] = '!';
    }

    sy--;
}

void remove_y(int num){
//    cout << "縦列消去: " << num << endl;

    for(int x = num;x < sx;x++){
        
        for(int y = 1;y < sy+1;y++){
            a[x][y] = a[x+1][y];
        }

    }

    for(int y = 1;y < sy+1;y++){
        a[sx][y] = '!';
    }

    sx--;
}

bool solve(){
    int p = 0;

    // 縦のラインをチェック
    for(int x = 1;x < sx+1;x++){
        p = 0;
        for(int y = 1;y < sy + 1;y++){
            if(a[x][y] == '.'){
                p++;
            }
            if(p == sy){
                remove_y(x);
                return false;
            }
        }
    }

//    cout << "横チェック" << endl;

    // 横のラインをチェック
    for(int y = 1;y < sy+1;y++){
        p = 0;
        for(int x = 1;x < sx + 1;x++){
            if(a[x][y] == '.'){
                p++;
            }
            if(p == sx){
                remove_x(y);
                return false;
            }
        }
    }

    return true;
}

int main(){
    cin >> H >> W;
    for(int y = 1;y < H+1;y++){
        for(int x = 1;x < W+1;x++){
            cin >> a[x][y];
        }
    }

    sx = W;
    sy = H;

    while(1){
        if(solve()){
            break;
        }
    }

    for(int y = 1;y < sy+1;y++){
        for(int x = 1;x < sx+1;x++){
                cout << a[x][y];
        }
        cout << endl;
    }
}