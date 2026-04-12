#include <iostream>
#include <string>
using namespace std;

int main(void){
    int h, w;
    char a[9][9];
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> a[i];
    
    bool t[9][9];
    for (int i = 0; i < h * w; i++) {
        if (a[i / w][i % w] == '#') t[i / w][i % w] = true;
        else t[i / w][i % w] = false;
    }
    for (int i = 0; i < h; i++) t[i][w] = false;
    for (int i = 0; i < w; i++) t[h][i] = false;
    
    int k = 0;
    while (k != h * w - 1) {
        if (t[k / w + 1][k % w] && !t[k / w][k % w + 1]) {
            t[k / w][k % w] = false;
            k += w;
        }
        else if (!t[k / w + 1][k % w] && t[k / w][k % w + 1]) {
            t[k / w][k % w] = false;
            k += 1;
        }
        else {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    
    for (int i = 0; i < h * w - 1; i++) {
        if (t[i / w][i % w]) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    
    cout << "Possible" << endl;
    return 0;
    
}
