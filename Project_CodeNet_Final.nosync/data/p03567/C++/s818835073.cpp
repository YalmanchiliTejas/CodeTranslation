#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool ans = 0;
    for (int i = 1; i < (int)s.size(); i++)
        if (s[i] == 'C' && s[i - 1] == 'A')
            ans = 1;

    if (ans) cout << "Yes";
    else cout << "No";

    return 0;
}
