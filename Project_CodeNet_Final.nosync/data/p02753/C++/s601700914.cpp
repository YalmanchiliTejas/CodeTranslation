#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    bool ans=true;
    if (s[0] == s[1] && s[1] == s[2]) ans = false;

    cout << (ans ? "Yes" : "No") << endl;
}
