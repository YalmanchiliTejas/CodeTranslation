#include <iostream>

int main( void ) {
    int r, g, b;

    // 3つの数の並びを読み込む
    std::cin >> r >> g >> b;

    // r, g, bを左から並べるということは
    // つまり
    // 100の位はr
    //  10の位はg
    //   1の位はb
    // ということ。
    // そこで、実際にそういう数を作ってみる。
    const int number = r*100 + g*10 + b*1;

    // 並べた数が4の倍数かどうかを調べる。
    // 4の倍数であるということは、
    // 「4で割ってあまりがない(0である)」
    // ということだ。
    if( number % 4 == 0 ) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}