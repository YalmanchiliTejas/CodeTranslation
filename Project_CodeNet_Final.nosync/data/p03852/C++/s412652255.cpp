#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	char c; cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'o' || c == 'e')cout << "vowel\n";
	else cout << "consonant\n";
}