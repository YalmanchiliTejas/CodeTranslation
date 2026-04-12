// AOJ 2252

#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	map <char, int> data;
	data['a'] = 1;
	data['b'] = 1;
	data['c'] = 1;
	data['d'] = 1;
	data['e'] = 1;
	data['f'] = 1;
	data['g'] = 1;
	data['h'] = 0;
	data['i'] = 0;
	data['j'] = 0;
	data['k'] = 0;
	data['l'] = 0;
	data['m'] = 0;
	data['n'] = 0;
	data['o'] = 0;
	data['p'] = 0;
	data['q'] = 1;
	data['r'] = 1;
	data['s'] = 1;
	data['t'] = 1;
	data['u'] = 0;
	data['v'] = 1;
	data['w'] = 1;
	data['x'] = 1;
	data['y'] = 0;
	data['z'] = 1;

	string str;
	while (cin >> str){
		if (str == "#") break;
		int now, prev = data[str[0]];
		int ret = 0;
		for (int i = 0; i < (int)str.length(); i++){
			now = data[str[i]];
			if (now != prev){
				ret++;
			}
			prev = now;
		}
		cout << ret << endl;
	}

	return 0;

}