#include <bits/stdc++.h>
using namespace std;

int main() {
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};
  char a;
  cin >> a;
  for (int i = 0; i < sizeof(vowels); i++) {
  	if (vowels[i] == a) {
    	cout << "vowel" << endl;
      	return 0;
    }
  }
  cout << "consonant" << endl;
}
