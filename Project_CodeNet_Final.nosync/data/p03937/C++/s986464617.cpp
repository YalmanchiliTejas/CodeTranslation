#include <iostream>
#include <string>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    int count = 0;
    for (int i = 0; i < H; ++i) {
        string S; cin >> S;
        for (auto c : S) if (c == '#') ++count;
    }
    if (count == H + W - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
