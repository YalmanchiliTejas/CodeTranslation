#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_s(i, s, n) for (int i = (int)(s); i < (int)(n); i++)

int main()
{
    string c;
    cin >> c;
    if (c == "a" || c == "e" || c == "i" || c == "u" || c == "o")
    {
        cout << "vowel" << endl;
    }
    else
    {
        cout << "consonant" << endl;
    }
}
