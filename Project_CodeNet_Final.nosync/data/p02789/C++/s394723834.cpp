// ConsoleApplication3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    cin >> M;
    if (N == M) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}