#include <iostream>
#include <map>
using namespace std;

int main(void){
	map<char, int>	key;
    key['q'] = 1;
    key['w'] = 1;
    key['e'] = 1;
    key['r'] = 1;
    key['t'] = 1;
    key['a'] = 1;
    key['s'] = 1;
    key['d'] = 1;
    key['f'] = 1;
    key['g'] = 1;
    key['z'] = 1;
    key['x'] = 1;
    key['c'] = 1;
    key['v'] = 1;
    key['b'] = 1;
    key['y'] = 0;
    key['u'] = 0;
    key['i'] = 0;
    key['o'] = 0;
    key['p'] = 0;
    key['h'] = 0;
    key['j'] = 0;
    key['k'] = 0;
    key['l'] = 0;
    key['n'] = 0;
    key['m'] = 0;

	string input;
	while(cin >> input && input != "#"){
		int changed = 0;
		int now = key[input[0]];
		for(int i = 1; i < input.size(); i++){
			if(key[input[i]] != now){
				now = key[input[i]];
				changed++;
			}
		}
		cout << changed << endl;
	}
  return 0;
}