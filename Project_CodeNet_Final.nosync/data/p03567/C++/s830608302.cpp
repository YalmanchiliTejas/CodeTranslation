#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;


int main(void) {
    string s;
    cin >> s;
    Int length = (Int)s.length();
    bool result = false;
    for (Int i = 0; i < length - 1; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            result = true;
        }
    }
    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
