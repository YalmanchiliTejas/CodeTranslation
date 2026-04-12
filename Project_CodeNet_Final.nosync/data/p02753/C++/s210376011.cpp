#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < n; i++) 

using namespace std;

int main() {
    char a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << "No" << endl;
        return 0;
    }
    else if (a != b != c) {
        cout << "Yes" << endl;
    }
    return 0;
}