#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    // 配列の最大値を取得
    int max = *max_element(vec.begin(), vec.end());
    // 配列の最大値のイテレータを取得
    vector<int>::iterator maxIt = max_element(vec.begin(), vec.end());
    // 配列の最大値までの距離を取得
    int maxIndex = distance(vec.begin(), maxIt);
    // 隣り合う重複要素を削除し、末尾のゴミを削除
    // (uniqueは、重複を取り除いた範囲の末尾の次を指すイテレータを返す)
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
*/

int main() {
    int h, w;
    cin >> h >> w;
    char a[h][w];

    vector<int> row(h, 1);
    vector<int> cols(w, 1);

    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                row[i] = 0;
                cols[j] = 0;
            }
        }
    }

    for (int i=0; i<h; ++i) {
        if (row[i]) continue;
        for (int j=0; j<w; ++j) {
            if (cols[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}


