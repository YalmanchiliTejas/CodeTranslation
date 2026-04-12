#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;

int main() {
    int H, W, count = 0;
    cin >> H >> W;
    for (int i = 0; i < H * W; i++) {
        char A;
        cin >> A;
        if (A == '#') {
            count++;
        }
    }
    if (count == H + W - 1) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}
