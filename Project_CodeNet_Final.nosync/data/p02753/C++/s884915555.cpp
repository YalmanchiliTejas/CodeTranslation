#include <iostream>
#include <string>

int main()
{
    using namespace std;

    string str;

    cin >> str;

    if(str == "AAA" || str == "BBB")
    {
        cout << "No" << endl;
    } else
    {
        cout << "Yes" << endl;
    }

    return 0;
}
