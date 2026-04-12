#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    string bo = "aiueo";
    string c;
    cin >> c;
    if (bo.find(c) == string::npos) {
        cout << "consonant" << endl;
    } else {
        cout << "vowel" << endl;
    }

    return 0;
}
