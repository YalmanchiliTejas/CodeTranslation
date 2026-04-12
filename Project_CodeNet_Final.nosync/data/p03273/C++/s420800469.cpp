#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    for (int i = 0; i < H; i++) {
        cin >> field[i];
    }

    vector<string> field2;
    for (int i = 0; i < H; i++) {
        bool w = true;
        for (int j = 0; j < W; j++) {
            if (field[i][j] == '#') {
                w = false;
                break;
            }
        }

        if (!w) {
            field2.push_back(field[i]);
        }
    }

    H = field2.size();
    vector<string> field3(H);
    for (int i = 0; i < W; i++) {
        bool w = true;
        for (int j = 0; j < H; j++) {
            if (field2[j][i] == '#') {
                w = false;
                break;
            }
        }

        if (!w) {
            for (int j = 0; j < H; j++) {
                field3[j].push_back(field2[j][i]);
            }
        }
    }

    for (auto e : field3) {
        cout << e << endl;
    }

    return 0;
}
