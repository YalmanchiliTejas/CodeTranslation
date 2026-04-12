#include <iostream>
using namespace std;
int main() {
char c;
cin >> c;
char *s = "aiueo";
bool a = false;
for (int i = 0; i < 5; ++i) if (c == s[i]) {
a = true;
}
if (!a) cout << "consonant" << endl;
else cout << "vowel" << endl;
}