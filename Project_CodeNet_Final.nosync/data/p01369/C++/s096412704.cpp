#include <iostream>
#include <string>

using namespace std;

int main(){
	string buf;
	//left = 0, right = 1
	int table[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, state, c;
	while(cin >> buf){
		c = 0;
		if(buf[0] == '#') break;
		state = table[buf[0] - 'a'];
		for(int i = 1;i < buf.length();++i){
			if(state != table[buf[i] - 'a']){
				state = table[buf[i] - 'a'];
				++c;
			}
		}
		cout << c << endl;
	}
	return 0;
}