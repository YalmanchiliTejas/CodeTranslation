// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    char a[105][105];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
           
        }
    }
    vector<int> tate(h, 0);
    for (int i = 0; i < h; i++) {
        bool ok = true;
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') {
                ok = false;
                break;
            }
        }
        if (ok) {
            tate[i] = 1;
        }
    }
    vector<int>yoko(w, 0);
    for (int i = 0; i < w; i++) {
        bool ok = true;
        for (int j = 0; j < h; j++) {
            if (a[j][i] == '#') {
                ok = false;
                break;
            }
        }
        if (ok) {
            yoko[i] = 1;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (tate[i] == 0 && yoko[j] == 0) {
                cout << a[i][j];
            }
        }
        if(tate[i]==0)cout << endl;
    }
    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
