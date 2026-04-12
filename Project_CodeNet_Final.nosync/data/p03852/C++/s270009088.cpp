#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
string s;
int main() {
  cin>>s;
  if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
  	cout<<"vowel"<<endl;
  } else {
  	cout<<"consonant"<<endl;
  }
	return 0;
}