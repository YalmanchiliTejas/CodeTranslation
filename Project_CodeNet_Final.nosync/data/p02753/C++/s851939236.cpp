#include <iostream>

using namespace std;
int main()
{
    string s;
    cin >> s;

    bool b = false;
    for(int i=1; i<3; i++) {
        if(s[i] != s[0]) b=true;
    }

    cout << (b ? "Yes" : "No");
    return 0;
}