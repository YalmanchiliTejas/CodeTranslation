#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    
    char A[64];
    for (int i=0; i < H * W; ++i) cin >> A[i];
    
    int r = 0;
    
    string res = "Possible";
    
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (A[w+h * W] == '#' && w < r) {
                res = "Impossible";
            }
            else if (A[w+h * W] == '#') r = w;
        }
    }
    
    cout << res << endl;
}