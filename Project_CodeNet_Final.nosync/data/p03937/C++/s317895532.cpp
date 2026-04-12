#include <iostream>
using namespace std;
int H, W;
char A[10][10];

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) cin >> A[i];
    
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') cnt++;
        }
    }
    if (cnt == H + W - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}