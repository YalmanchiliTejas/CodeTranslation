#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s.compare("AAA") == 0 || s.compare("BBB") == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    
    return 0;
}
