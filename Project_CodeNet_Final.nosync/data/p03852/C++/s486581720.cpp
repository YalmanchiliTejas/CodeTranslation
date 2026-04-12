#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <iomanip>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    char a;

    cin >> a;
    
    if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o') {
        cout << "vowel" << endl;
    }
    else {
        cout << "consonant" << endl;
    }
}
