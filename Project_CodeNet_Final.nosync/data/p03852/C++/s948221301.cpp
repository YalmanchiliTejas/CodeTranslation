#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string vowels = "aeiou";
    char c;
    cin >> c;
    if(find(vowels.begin(), vowels.end(), c) != vowels.end())
        cout << "vowel";
    else
        cout << "consonant";

    return 0;
}
