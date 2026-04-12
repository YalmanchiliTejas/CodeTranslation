#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;


int main()
{
    int H, W;
    cin >> H >> W;
    
    vector<string> A(H);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }
    
    vector<bool> row(H, false);
    vector<bool> col(W, false);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    
    for (int i = 0; i < H; i++) {
        if (row[i]) {
            for (int j = 0; j < W; j++) {
                if (col[j]) {
                    cout << A[i][j];
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}