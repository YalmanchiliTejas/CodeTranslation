#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char fst = s[0];
    if (fst != s[1] || fst != s[2])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}