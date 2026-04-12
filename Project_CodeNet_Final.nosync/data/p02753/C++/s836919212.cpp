// 4/30
// 過去問攻略

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    char S[3];
    cin >> S;

    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        if (S[i] == 'A') a++;
        else b++;
    }

    if (a != 0 && b != 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
