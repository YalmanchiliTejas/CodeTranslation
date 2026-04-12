#include <iostream>
#include <string>
using namespace std;
int main()
{
    string text;
    cin >> text;
    if (text == "AAA" || text == "BBB")
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
}