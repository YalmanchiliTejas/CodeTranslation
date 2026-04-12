#include <iostream>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    char a[h][w + 1];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }

    bool is_black_h[h];
    for (int i = 0; i < h; i++){
        is_black_h[i] = 0;
        for (int j = 0; j < w; j++){
            if (a[i][j] == '#'){
                is_black_h[i] = 1;
                break;
            }
        }
    }

    bool is_black_w[w];
    for (int j = 0; j < w; j++){
        is_black_w[j] = 0;
        for (int i = 0; i < h; i++){
            if (a[i][j] == '#'){
                is_black_w[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < h; i++){
        if (is_black_h[i]){
            for (int j = 0; j < w; j++){
                if (is_black_w[j]){
                    cout << a[i][j];
                }
            }

            cout << endl;
        }
    }

    return 0;
}