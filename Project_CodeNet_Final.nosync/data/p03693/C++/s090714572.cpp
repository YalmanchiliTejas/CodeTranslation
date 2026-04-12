#include <iostream>

using namespace std;

int main(){
    int r;
    //rを定義
    int g;
    //gを定義
    int b;
    //bを定義
    cin >> r >> g >>b;
    if((r * 100 + g * 10 + b) % 4 == 0){
        cout << "YES" << endl;
        //rgbが4の倍数の場合YESと出力
    } else {
        cout << "NO" << endl;
        //それ以外はNOと出力
    }
}