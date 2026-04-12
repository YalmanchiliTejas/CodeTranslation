#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    string ans = "consonant";
    cin >> c;
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
    {
        ans = "vowel";
    }
    cout << ans << endl;
}