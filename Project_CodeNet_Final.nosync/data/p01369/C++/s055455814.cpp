#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	char f[256] = {0};
	f['y'] = 1;
	f['u'] = 1;
	f['i'] = 1;
	f['o'] = 1;
	f['p'] = 1;
	f['h'] = 1;
	f['j'] = 1;
	f['k'] = 1;
	f['l'] = 1;
	f['n'] = 1;
	f['m'] = 1;

	
	while( cin >> s ){
		if( s == "#" ) break;
		
		int ans = 0;
		int state = f[ s[0] ];
		for(int i=1 ; i < (int)s.size() ; i++ ){
			if( state != f[ s[i] ] )
				ans++;
			state = f[ s[i] ];
		}
		cout << ans << endl;
	}
}