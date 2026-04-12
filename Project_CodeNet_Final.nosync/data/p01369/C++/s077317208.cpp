#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<char,bool> qwer;
	qwer['q'] = false;
	qwer['w'] = false;
	qwer['e'] = false;
	qwer['r'] = false;
	qwer['t'] = false;
	qwer['a'] = false;
	qwer['s'] = false;
	qwer['d'] = false;
	qwer['f'] = false;
	qwer['g'] = false;
	qwer['z'] = false;
	qwer['x'] = false;
	qwer['c'] = false;
	qwer['v'] = false;
	qwer['b'] = false;

	qwer['y'] = true;
	qwer['u'] = true;
	qwer['i'] = true;
	qwer['o'] = true;
	qwer['p'] = true;
	qwer['h'] = true;
	qwer['j'] = true;
	qwer['k'] = true;
	qwer['l'] = true;
	qwer['n'] = true;
	qwer['m'] = true;

	string str;
	while(cin >> str){
		if(str[0] == '#')
			break;
		int count = 0;
		for(unsigned i=1;i<str.size();i++){
			if(qwer[str[i-1]] != qwer[str[i]])
				count++;
		}
		cout << count << endl;
	}
	return 0;
}