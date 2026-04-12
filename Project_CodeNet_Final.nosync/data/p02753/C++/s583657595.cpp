#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int main() {
    bool hasA = false, hasB = false;
    string s;
    cin >> s;
    for (char c: s) {
        if (c == 'A') hasA = true;
        else hasB = true;
    }

    cout << ((hasA && hasB) ? "Yes" : "No");

    return 0;
}
