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
    int x; cin >> x;

    if (x == 7 || x == 5 || x == 3) cout << "YES";
    else cout << "NO";

    cout << endl;
}


