#include <bits/stdc++.h>
using namespace std;

int main() {
    //変数宣言
    int a, b, c;

    //入力受付
    cin >> a >> b >> c;
    
    //計算
    int x = (a * 100) + (b * 10) + c;

    //出力
    if (x % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}