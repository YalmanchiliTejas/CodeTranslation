#include <iostream>
#include <string>

using namespace std;

int main(){
	string input, tmp = "qwertasdfgzxcvb";
	int hand[32], count;
	int i;
	
	while(1){
		cin >> input;
		
		if(input == "#")
			break;
		
		count = 0;
		for(i = 0; i < input.size(); i++){
			if(tmp.find(input[i]) != -1)
				hand[i] = 0;
			else
				hand[i] = 1;
		}
		for(i = 1; i < input.size(); i++)
			if(hand[i] != hand[i - 1])
				count++;
		
		cout << count << endl;
	}
	
	return 0;
}