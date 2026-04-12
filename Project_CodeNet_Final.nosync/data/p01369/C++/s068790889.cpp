#include <iostream>
#include <string>

using namespace std;

string qwerty = "yuiophjklnm";
int check(char c){
	for(int i = 0; i < qwerty.size(); i++){
		if(qwerty[i] == c) return 1; //right 
	}
	return 0; //left
}

int main(){
	string s;
	while(cin >> s, s != "#"){
		int prev = check(s[0]);
		int cnt = 0;
		for(int i = 1; i < s.size(); i++){
			int cur = check(s[i]);
			if (prev != cur) cnt++;
			prev = cur;
		}
		cout << cnt << endl;
	}

	return 0;
}