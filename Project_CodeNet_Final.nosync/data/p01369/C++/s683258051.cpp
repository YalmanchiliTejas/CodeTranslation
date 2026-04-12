#include <iostream>
#include <vector>

using namespace std;

int main(void){
	while(1){
		string str; cin >> str;
		if(str == "#") break;
		string left="yuiophjklnm";
		for(int i=0; i<str.size(); i++){
			if(left.find(str[i]) != left.npos) str[i] = '0';
			else str[i] = '1';
		}
		int ans = 0;
		for(int i=1; i<str.size(); i++){
			if(str[i-1] != str[i]) ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
