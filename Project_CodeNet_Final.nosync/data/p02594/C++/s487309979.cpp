#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char* argv[]) {

    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    int X;
    cin >> X;
    if (X < 30) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    /////////////////////

    return 0;
}