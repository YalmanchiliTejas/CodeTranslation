#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if ((s[0] == 'A' && s[1] == 'C') || (s[1] == 'A' && s[2] == 'C') || (s[2] == 'A' && s[3] == 'C') || (s[3] == 'A' && s[4] == 'C'))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}