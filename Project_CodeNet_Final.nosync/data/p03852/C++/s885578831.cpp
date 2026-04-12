#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
    string c;
    cin >> c;

    regex format("[aiueo]");

    if (regex_match(c, format))
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}