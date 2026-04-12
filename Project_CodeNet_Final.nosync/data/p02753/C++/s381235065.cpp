#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;

    string output = "Yes";
    if (s[0] == s[1] && s[1] == s[2]) {
        output = "No";
    }

    cout << output << endl;
    return 0;
}
