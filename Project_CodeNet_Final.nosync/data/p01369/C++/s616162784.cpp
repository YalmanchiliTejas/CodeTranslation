#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int Lefthand(std::string c) {
	if (c == "#") {
		return -1;
	}else if(c == "y"||c == "u"||c == "i"||c == "o"||c == "p"||c == "h"||c == "j"||c == "k"||c == "l"||c == "n"||c == "m"){
		return 0;
	}else {
		return 1;
	}
}

int main(void) {
	char c;
	std::string str;
	std::string dstr;
	getline(cin, str);
	dstr = str.substr(0,1);
	int mode;
	mode = Lefthand(dstr);
	
	while (!(mode < 0)) {
		int change_num = 0;
		for (int i = 0; i < (str.length()-1); i++) {
			bool seq = true;	
			dstr = str.substr(i,1);
			mode = Lefthand(dstr);
			while (seq && i < (str.length()-1)) {
					int mode_next;
					dstr = str.substr(i+1,1);
					mode_next = Lefthand(dstr);
					if (mode != mode_next) {
						change_num++;
						seq = false;
					} else{
						i++;
					}
			}
		}
		cout << change_num << endl;
		getline(cin, str);
		dstr = str.substr(0,1);
		mode = Lefthand(dstr);
	}
	return 0;
}