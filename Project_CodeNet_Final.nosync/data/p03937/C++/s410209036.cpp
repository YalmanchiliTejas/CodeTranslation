#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    
    char A[64];
    for (int i=0; i < H * W; ++i) cin >> A[i];
    
    int sharp = 0;
    for (int i=0; i < H * W; ++i) {
        if (A[i] == '#') ++sharp;
    }
    
    if (sharp == H + W -1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}