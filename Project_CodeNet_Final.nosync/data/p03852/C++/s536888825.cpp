#include <iostream>
#include <string>

using namespace std;

int main()
{
    string vowel = "aiueo";
    string c;
    cin >> c;
    if (vowel.find(c) != string::npos) cout << "vowel" << endl;
    else cout << "consonant" << endl;

    return 0;
}
