#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    vector<bool> good_x(w, false);
    vector<bool> good_y(h, false);
    for (int i = 0; i < h; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == '#') {
                good_y[i] = true;
                good_x[j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        if (good_y[i] == false) {
            continue;
        }
        for (int j = 0; j < w; j++) {
            if (good_x[j] == false) {
                continue;
            }
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}