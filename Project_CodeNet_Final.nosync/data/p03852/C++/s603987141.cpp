#include <iostream>
using namespace std;

int main()
{
    string c;
    cin >> c;

    string bowel = "aiueo";
    bool isVowel = (bowel.rfind(c) != string::npos);

    cout << (isVowel ? "vowel" : "consonant") << endl;
    return 0;
}