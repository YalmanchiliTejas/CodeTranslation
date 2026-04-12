#include <iostream>
using namespace std;
string c, x="aeiou";
int main() {
	cin>>c;
	cout<<(x.find(c)<5 ? "vowel" : "consonant");
	return 0;
}