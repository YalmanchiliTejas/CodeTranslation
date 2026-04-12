#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    cout << ( S[0] == 'a' || S[0] == 'i' || S[0] == 'u' || S[0] == 'e' || S[0] == 'o' ?
             "vowel" : "consonant" ) << endl;
    return 0;
}