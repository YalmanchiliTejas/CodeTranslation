#include <iostream>
#include <set>

using namespace std;

int main()
{
    char c;
    cin >> c;

    set<char> s;

    s.insert('a');
    s.insert('e');
    s.insert('i');
    s.insert('o');
    s.insert('u');

    cout << ((s.find(c) != s.end())? "vowel" : "consonant") << endl;

    return 0;
}