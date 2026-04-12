#include <iostream>
#include <string>
using namespace std;
int main() {
char c;
cin >> c;
string vowel = "aeiou";
if (vowel.find(c) != -1) cout << "vowel" << endl;
else cout << "consonant" << endl;
}