#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    cin >> c;

    string vowel = "aeiou";

    bool is_vowel = false;
    for (int i = 0; i < 5; i++)
    {
        char v = vowel.at(i);
        if (c == v)
        {
            is_vowel = true;
            break;
        }
    }
    if (is_vowel)
    {
        cout << "vowel" << endl;
    }
    else
    {
        cout << "consonant" << endl;
    }
}