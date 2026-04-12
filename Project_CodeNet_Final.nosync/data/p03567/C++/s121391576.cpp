#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i=0; i<s.length()-1; i++)
        if (s.substr(i,2) == "AC") return cout << "Yes" << endl, 0;

    cout << "No" << endl;

    return 0;
}
