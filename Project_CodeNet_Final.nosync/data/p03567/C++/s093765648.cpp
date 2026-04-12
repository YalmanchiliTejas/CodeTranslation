#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int first = str.find('A');
    int last = str.find('C');
    if ((first >= 0) && ((first + 1) == last))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}