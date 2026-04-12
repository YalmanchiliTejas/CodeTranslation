#include <iostream>
using namespace std;

int main() {
    int H,W,p = 0;
    bool out = true;
    char A;
    cin >> H >> W;
    for(int i = 0;i < H;i++) {
        for(int t = 0;t < W;t++) {
            cin >> A;
            if(out) {
                if(t < p) {
                    if(A == '#') {
                        out = false;
                        break;
                    }
                    continue;
                }
                if(A == '#') {
                    p = t;
                }
            }
        }
    }
    cout << (out ? "Possible" : "Impossible") << endl;
}