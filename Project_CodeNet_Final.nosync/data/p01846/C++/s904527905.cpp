#include <iostream>
#include <algorithm>
using namespace std;

string S;
int A, B, C, D;

int main() {
    int data[10][10];

    while (true) {
        cin >> S;
        if (S == "#") { break; }
        cin >> A >> B >> C >> D;
        --A; --B; --C; --D;
        for (int j = 0; j < 10; ++j) { fill(data[j], data[j]+10, 0); }

        int h = 0;
        int w = 0;
        for (int j = 0; j < (int)S.size(); ++j) {
            if (S[j] == '/') { ++h; w = 0; }
            else if (S[j] == 'b') { data[h][w] = 1; ++w; }
            else { w += S[j] - '0'; }
        }
        ++h;

        swap(data[A][B], data[C][D]);

        for (int j = 0; j < h; ++j) {
            if (j > 0) { cout << "/"; }
            int acc = 0;
            for (int k = 0; k < w; ++k) {
                if (data[j][k] == 1) {
                    if (acc > 0) { cout << acc; }
                    acc = 0;
                    cout << "b";
                } else {
                    ++acc;
                }
            }
            if (acc > 0) { cout << acc; }
        }
        cout << endl;
    }
    return 0;
}