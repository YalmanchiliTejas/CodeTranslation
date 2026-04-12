#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int j = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') {
            j++;
        }
    }
    if (j == 0 || j == 3) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}