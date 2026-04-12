#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> vowels{'a', 'i', 'u', 'e', 'o'};
    char c;
    cin >> c;

    for (auto v : vowels)
    {
        if (v == c)
        {
            cout << "vowel";
            return 0;
        }
    }
    cout << "consonant";
}