#include <iostream>
using namespace std;

int main(){
    int r, g, b;/*int型変数r,g,bを定義*/
    cin >> r >> g >> b;/*変数r,g,bに標準入力を格納*/
    int c = 100 * r + 10 * g + b;/*int型変数cを定義し変数r,g,bで3桁の整数を作り変数cに格納*/
    if (c % 4 == 0) cout << "YES" << endl;/*変数cが4の倍数ならYESを出力*/
    else cout << "NO" << endl;/*4の倍数でないならNOを出力*/
}