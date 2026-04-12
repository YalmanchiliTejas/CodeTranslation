#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;

    char replace = s[k-1];
    for (int i = 0; i < n; i++) {
        if (replace != s[i]) {
            s[i] = '*';
        }
    }
    cout << s << endl;
}

