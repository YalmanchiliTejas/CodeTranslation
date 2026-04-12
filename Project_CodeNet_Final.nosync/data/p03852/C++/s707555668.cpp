#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<char> dict {'a', 'e', 'i', 'o', 'u'};
    char c;
    cin >> c;
    if (dict.find(c) == dict.end()) {
        cout << "consonant" << endl;
    } else {
        cout << "vowel" << endl;
    }
    return 0;
}