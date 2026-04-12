#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    cin >> c;

    string vowel = "aiueo";

    if (vowel.find(c) == string::npos)
    {
        cout << "consonant" << endl;
    }
    else
    {
        cout << "vowel" << endl;
    }
}
