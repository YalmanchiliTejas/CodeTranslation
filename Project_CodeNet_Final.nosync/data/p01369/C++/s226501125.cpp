#include<iostream>
#include<string>
using namespace std;


int main(){
	string right("yuiophjklnm");
	string input;
	while(cin >> input, input != "#"){
		int count = 0;
		int shefting = 0;

		for(int i=0; i < input.length(); i++){
			bool isRight = false;
			for(int j=0; j < right.length(); j++){
				if(input[i] == right[j]){
					isRight = true;
					break;
				}
			}
			if(isRight && shefting != 1){
				isRight = false;
				shefting = 1;
				count++;
			}
			else if(!isRight && shefting != 2){
				shefting = 2;
				count++;
			}
		}
		cout << count-1 << endl;
	}
}