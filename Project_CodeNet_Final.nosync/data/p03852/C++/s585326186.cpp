#include <algorithm>
#include <bitset>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main()
{
    char c;
    cin >> c;
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
        cout << "vowel\n";
    } else {
        cout << "consonant\n";
    }
}
