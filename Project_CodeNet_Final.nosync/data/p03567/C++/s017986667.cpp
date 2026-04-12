#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    char x[5];
    cin >> x;
    if(strstr(x,"AC"))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << endl;
    return 0;
}