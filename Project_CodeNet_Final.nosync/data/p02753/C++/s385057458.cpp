#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
//--------------------
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void func() {
    string s;
    cin >> s;
    int a = 0;
    for (auto ch: s) {
        if( ch == 'A') {
             a += 1;
        }
    }
    cout << ((a == 3 || a == 0) ? "No" : "Yes") << endl;
}

int main() {
    func();
    return 0;
}