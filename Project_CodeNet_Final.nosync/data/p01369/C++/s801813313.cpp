#include <bits/stdc++.h>

using namespace std;

int main(void){
	string str;
	string right = "yuiophjklnm";
	while(1){
		getline(cin, str);
		if(str == "#"){
			break;
		}
		int count = 0;
		char position;

		for(int i = 0; i < str.size(); i++){
			if(i == 0){
				if(find(right.begin(),right.end(),str[i]) == right.end()){
					position = 'l';
				}else{
					position = 'r';
				}
			}
			if(position == 'r' and find(right.begin(),right.end(),str[i]) == right.end()){
				count++;
				position = 'l';
			}else if(position == 'l' and find(right.begin(),right.end(),str[i]) != right.end()){
				count++;
				position = 'r';
			}
		}
		cout << count << endl;
	}
	return 0;
}