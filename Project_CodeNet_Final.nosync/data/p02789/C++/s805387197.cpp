#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int H;
    int W;

    cin >> H >> W;

    if (H == W) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
