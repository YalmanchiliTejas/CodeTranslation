// AirConditioner.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int x;
    string out;
    cin >> x;
    if (x >= 30) {
        out = "Yes";
    }
    else {
        out = "No";
    }
    std::cout << out;
    return 0;
}
