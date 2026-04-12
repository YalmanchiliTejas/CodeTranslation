#include <iostream>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    char masu[105][105];
    int check_tate[105];
    int check_yoko[105];
    for(int i = 0; i < 105; i++){
        check_yoko[i] == 0;
        check_tate[i] == 0;
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c;
            cin >> c;
            masu[i][j] = c;
            if(c == '#'){
                check_tate[j] = 1;
                check_yoko[i] = 1;
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(check_tate[j] == 1 && check_yoko[i] == 1){
                cout << masu[i][j];
            }
        }
        if(check_yoko[i] == 1){
            cout << endl;
        }
    }
    return 0;
}