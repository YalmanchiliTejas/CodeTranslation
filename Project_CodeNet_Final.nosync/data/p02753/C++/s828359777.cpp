#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s == "AAA" or s == "BBB") {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    return 0;
}
