#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(void) {
    int H,W;cin>>H>>W;
    pair<int, int> pv[H];
    for (int i = 0; i < H; i++) {
        string a;cin>>a;
        int start = -1;
        int end = -1;
        pair<int, int> p;
        for (int j = 0; j < W; j++) {
            char c = a[j];
            if (start == -1 && c == '#') {
                start = j;
            }
            if (c == '#') end = j;
        }
        p = make_pair(start, end);
        pv[i] = p;
    }
    for (int i = 0; i < H - 1; i++) {
        pair<int, int> before = pv[i];
        pair<int, int> next = pv[i+1];
        if (before.second > next.first) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}