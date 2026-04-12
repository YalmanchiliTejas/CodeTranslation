#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int p_count = 0;
int H, W;
char A[8][8];
string ans = "Impossible";

void solution(int h, int w, int count) {
    if (h >= H || w >= W) {
        return;
    }
    if (A[h][w] == '.') {
        return;
    }
    if (h == H-1 && w == W-1 && count == p_count) {
        ans = "Possible";
        return;
    }
    solution(h+1, w, count+1);
    solution(h, w+1, count+1);
}

int main() {
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (A[i][j] == '#') {
                p_count++;
            }
        }
    }
    solution(0, 0, 1);
    cout << ans << endl;
}
