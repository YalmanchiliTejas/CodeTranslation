#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    char A[H][W];
    int cnt = 0;
    rep(i, H) {
        rep(j, W) {
            cin >> A[i][j];
            if(A[i][j] == '#') {
                cnt++;
            }
        }
    }

    if(cnt == H+W-1) {
        cout << "Possible" << endl;
        return 0;
    }
    else {
        cout << "Impossible" << endl;
        return 0;
    }
}