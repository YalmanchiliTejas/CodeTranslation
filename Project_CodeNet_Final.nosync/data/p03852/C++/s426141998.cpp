#include <bits/stdc++.h>
using namespace std;

int main(){
	char c;
	cin >> c;
	bool flag = false;
	
	if(c == 'a'){
		flag = true;
	}
	else if(c == 'i'){
		flag = true;
	}
	else if(c == 'u'){
		flag = true;
	}
	else if(c == 'e'){
		flag = true;
	}
	else if(c == 'o'){
		flag = true;
	}
	else{
		flag = false;
	}
	
	if(flag == true){
		cout << "vowel" <<endl;
	}
	else{
		cout << "consonant" << endl;
	}
}