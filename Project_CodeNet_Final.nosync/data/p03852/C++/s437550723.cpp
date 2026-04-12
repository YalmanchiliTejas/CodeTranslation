#include <iostream>
using namespace std;
char c, x[9]="aeiou";
int main() {
	int i;
	cin>>c;
	for(i=0; i<5; i++) if(x[i]==c) break;
	cout<<(i==5 ? "consonant" : "vowel");
	return 0;
}