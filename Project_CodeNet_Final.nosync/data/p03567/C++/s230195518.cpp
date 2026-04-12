#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
int main() {
    cin >> S;

    bool f = false;
    for (int i = 0; i < S.length() - 1; i++) {
        if (S.substr(i, 2) == "AC") {
            f = true;
            break;
        }
    }

    cout << (f ? "Yes" : "No") << endl;

    return 0;
}
