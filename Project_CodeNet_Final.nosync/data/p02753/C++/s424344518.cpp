#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
