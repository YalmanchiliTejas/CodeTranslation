#include <iostream>

using namespace std;

int main() {
    int L, W, gap;
    cin >> L >> W >> gap;
    cout << (L - gap) / (W + gap);
}