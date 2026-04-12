#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
	string ans[2] = {"vowel", "consonant"};
	string vowel[5] = {"a", "e", "i", "o", "u"};
	string c;
	cin >> c;
	int flag = 1;
	for(int i = 0; i < 5; i++){
		if(c == vowel[i]){
			flag = 0;
		}
	}
	cout << ans[flag];
}
