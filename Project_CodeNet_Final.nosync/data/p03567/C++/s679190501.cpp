#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    cin >> str;
    if (str.find("AC") != string::npos)
        cout << "Yes\n";
    else
        cout << "No\n";
}
