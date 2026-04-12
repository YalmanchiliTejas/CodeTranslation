#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
set<char> s;
int main()
{
    char str;
    while (cin>>str)
    {
     s.insert('a');s.insert('e');s.insert('i');
    s.insert('o'); s.insert('u');
    if (s.find(str)!=s.end())
        cout<<"vowel\n";
    else cout<<"consonant\n";
    }

    return 0;
}
