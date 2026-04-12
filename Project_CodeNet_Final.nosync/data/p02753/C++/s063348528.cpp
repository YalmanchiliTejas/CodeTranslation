#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define iFOR(idx, from, upto) for (int  idx = from; idx < upto; ++idx)
#define lFOR(idx, from, upto) for (long idx = from; idx < upto; ++idx)

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s == "AAA" || s == "BBB") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}
