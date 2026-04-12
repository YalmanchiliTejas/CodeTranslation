#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;

int main()
{
    char ch;
    cin >> ch;
    if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o')
    {
        cout << "vowel" << endl;
    }
    else
    {
        cout << "consonant" << endl;
    }
    return 0;
}