#include <iostream>
#include <string>

using namespace std;

int main(){
	string left = "qwertasdfgzxcvb";
	while(true){
		string input;
		cin >> input;
		if(input == "#"){ break; }
		int current = -1, answer = -1;
		for(int i = 0; i < input.size(); ++i){
			int side = (left.find_first_of(input[i]) != string::npos) ? 0 : 1;
			if(current != side){ ++answer; }
			current = side;
		}
		cout << answer << endl;
	}
	return 0;
}