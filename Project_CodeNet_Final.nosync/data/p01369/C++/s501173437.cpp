#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int f[256] = {0};
	f['q'] = f['w'] = f['e'] = f['r'] = f['t'] = 1;
	f['a'] = f['s'] = f['d'] = f['f'] = f['g'] = 1;
	f['z'] = f['x'] = f['c'] = f['v'] = f['b'] = 1;
	string s;
	while( cin >> s ){
		if( s == "#" ) break;

		int cnt = 0;
		int prev = f[ s[0] ];
		for(int i=1 ; i < s.size() ; i++ ){
			if( prev != f[ s[i] ] ){
				cnt++;
				prev = f[ s[i] ];
			}
		}
		cout << cnt << endl;
	}
}