#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    cin >> c;
    string ans[2] = {"vowel", "consonant"};
    cout << ans[!(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')] << endl;

    return 0;
}
