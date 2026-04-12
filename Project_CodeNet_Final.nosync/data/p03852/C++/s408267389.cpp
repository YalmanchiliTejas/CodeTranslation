#include<iostream>
using namespace std;
int main(){
	char c;
	cin >> c;
	int ans;
	switch(c){
		case 'a':
			ans=1;
			break;
		case 'i':
			ans=1;
			break;
		case 'u':
			ans=1;
			break;
		case 'e':
			ans=1;
			break;
		case 'o':
			ans=1;
			break;
		default:
			ans=0;
	}
	if(ans) cout << "vowel" << endl;
	else cout << "consonant" << endl;
}
