#include<iostream>
#define MAX 100
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int R[MAX] = {};
    int C[MAX] = {};
    char A[MAX][MAX];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (A[i][j] == '#') {
                R[i] = 1;
                C[j] = 1;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        if (R[i] > 0) {
            for (int j = 0; j < W; j++) {
                if (C[j] > 0) cout << A[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}