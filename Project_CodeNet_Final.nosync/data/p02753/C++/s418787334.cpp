#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    int cnt = 0;
    while (cin >> str) {
        for (const char &c : str)
            cnt += c == 'A';
        cout << (cnt != 0 && cnt != str.size() ? "Yes" : "No") << '\n';
    }
}