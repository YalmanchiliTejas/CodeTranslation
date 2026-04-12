#include <bits/stdc++.h>

using namespace std;

int main(){
	string vowel = "aioue";
	char input;
	string output;
	cin >> input;
	if(vowel.find(input) == string::npos){
		output = "consonant";
	}else{
		output = "vowel";
	}

	cout << output << endl;
}
