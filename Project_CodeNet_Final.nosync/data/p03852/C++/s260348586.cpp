#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    cin >> c;
    bool flg = (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
    cout << (flg ? "vowel" : "consonant") << endl;
}
