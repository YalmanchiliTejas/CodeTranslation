#include <iostream>

using namespace std;

int main() {
    int N;
    //食べた数
    cin >> N;
    //入力
    cout << 800 * N - 200 * (N / 15) << endl;
    //800円の食べ物をN回食べて、5回食べたら200円を引いて出力
}