#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    cin >> c;

    string vowel = "aeiou";
    string output = "consonant";
    for (int i = 0; i < vowel.size(); i++)
    {
        if (vowel.at(i) == c)
        {
            output = "vowel";
            break;
        }
    }
    cout << output << endl;
}
