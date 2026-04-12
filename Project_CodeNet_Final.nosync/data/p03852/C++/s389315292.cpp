#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    string str;

    cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        str = "vowel";
    }
    else {
        str = "consonant";
    }
    cout << str << endl;
    return 0;
}