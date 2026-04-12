// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

int main()
{
    int n;

    cin >> n;
    int h;

    int max = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (max <= h) {
            cnt++;
            max = h;
        }
    }

    cout << cnt << endl;

    return 0;
}

