#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (auto i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}