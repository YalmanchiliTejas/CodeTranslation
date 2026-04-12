#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string s = "aiueo", c;
	cin >> c;
	cout << (s.find(c) != -1 ? "vowel" : "consonant") << endl;
}