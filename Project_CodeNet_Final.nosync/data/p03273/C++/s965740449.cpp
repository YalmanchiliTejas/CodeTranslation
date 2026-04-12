#include <iostream>
#include <algorithm>
using namespace std;

bool erow[101];
bool ecol[101];
char table[101][101];
int main(void) {
    for (int i = 0; i < 101; i++) {
        erow[i] = true; ecol[i] = true;
    }

    int h, w; cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            char c; cin >> c;
            table[i][j] = c;
            if (c == '#')
                erow[i] = ecol[j] = false;
        }

    //cout << endl;

    for (int i = 0; i < h; i++)
        if (!erow[i]) {
            for (int j = 0; j < w; j++) {
                if (!ecol[j])
                    cout << table[i][j];
            }
            cout << endl;
        }

    return 0;
}