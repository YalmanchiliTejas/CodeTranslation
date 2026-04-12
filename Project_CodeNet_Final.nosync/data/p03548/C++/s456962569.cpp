#include<iostream>

int main(){
    int X, Y, Z;
    std::cin >> X >> Y >> Z;
    int cnt = X / (Z + Y);
    // 右端をチェック
    if(X - cnt * (Z + Y) < Z) cnt--;
    std::cout << cnt << std::endl;
    return 0;
}
