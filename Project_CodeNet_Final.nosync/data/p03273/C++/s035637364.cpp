// う　し　た　ぷ　に　き　あ　く　ん　笑
#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }

    bitset<100> whiterow, whitecolomn;

    for (int i = 0; i < h; i++) {
        bool is_white_row = true;
        for (int j = 0; j < w; j++) {
            is_white_row &= a[i][j] == '.';
            if (!is_white_row) break;
        }
        whiterow[i] = is_white_row;
    }

    for (int i = 0; i < w; i++) {
        bool is_white_column = true;
        for (int j = 0; j < h; j++) {
            is_white_column &= a[j][i] == '.';
            if (!is_white_column) break;
        }
        whitecolomn[i] = is_white_column;
    }

    for (int i = 0; i < h; i++) {
        if (whiterow[i]) continue;

        for (int j = 0; j < w; j++) {
            if (whitecolomn[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}
