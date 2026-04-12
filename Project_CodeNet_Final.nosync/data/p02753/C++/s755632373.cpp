#include <iostream>
using namespace std;


int main()
{
    string s;
    cin >> s;

    if (s.at(0) != s.at(1) || s.at(1) != s.at(2) || s.at(2) != s.at(0))
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}