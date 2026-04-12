#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

const int INF = 100000000;

int main(void) {
	map<char, int> key;
	key['q'] = 0;
	key['w'] = 0;
	key['e'] = 0;
	key['r'] = 0;
	key['t'] = 0;
	key['a'] = 0;
	key['s'] = 0;
	key['d'] = 0;
	key['f'] = 0;
	key['g'] = 0;
	key['z'] = 0;
	key['x'] = 0;
	key['c'] = 0;
	key['v'] = 0;
	key['b'] = 0;
	key['y'] = 1;
	key['u'] = 1;
	key['i'] = 1;
	key['o'] = 1;
	key['p'] = 1;
	key['h'] = 1;
	key['j'] = 1;
	key['k'] = 1;
	key['l'] = 1;
	key['n'] = 1;
	key['m'] = 1;

	while(1){
		string s;
		int cnt = 0;

		cin >> s;
		if(s[0] == '#') break;
		
		int state = key[s[0]];
		for(int i=0; i<s.size(); i++){
			if(state != key[s[i]]) {
				cnt++;	
				state = key[s[i]];
			}
		}

		cout << cnt << endl;

	}
	
	return 0;
}