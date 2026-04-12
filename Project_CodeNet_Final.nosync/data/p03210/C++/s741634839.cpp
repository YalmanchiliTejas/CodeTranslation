#include <bits/stdc++.h>

using namespace std;

int main() {
    int X;
    cin >> X;
    bool ans = false;
    if (X == 7 || X == 5 || X == 3) {
        ans = true;
    }
    cout << (ans ? "YES" : "NO") << endl;
}
