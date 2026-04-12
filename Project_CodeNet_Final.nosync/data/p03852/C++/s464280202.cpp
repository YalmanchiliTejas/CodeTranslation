#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string c;
  	cin >> c;

  cout << (c.at(0) == 'a' || c.at(0) == 'i' || c.at(0) == 'u' || c.at(0) == 'e' || c.at(0) =='o' ? "vowel" : "consonant") << endl;
}