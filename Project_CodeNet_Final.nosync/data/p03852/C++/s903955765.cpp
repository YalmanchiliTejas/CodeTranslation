#include <bits/stdc++.h>
using namespace std;

int main() {
string s;
cin >> s;
int N = s.size();
for (int k = 0; k < N ; k++) {
if (s.at(k) == 'a') {
cout << "vowel" << endl;
break;
}
if (s.at(k) == 'i') {
cout << "vowel" << endl;
break;
}
if (s.at(k) == 'u') {
cout << "vowel" << endl;
break;
}
if (s.at(k) == 'e') {
cout << "vowel" << endl;
break;
}
if (s.at(k) == 'o') {
cout << "vowel" << endl;
break;
}
if (k == N-1) {
  cout << "consonant" << endl;
  break;
}
}
}
