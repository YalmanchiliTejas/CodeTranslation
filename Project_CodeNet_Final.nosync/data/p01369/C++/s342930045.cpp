#include <iostream>
#include <string>

using namespace std;

bool keymap[26] = {
	0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1,
	1, 1, 0, 0, 0, 0, 1,
	0, 0, 0, 1, 0
};
int main(){
	for(string s; cin >> s, s != "#";){
		int res = 0;
		for(int i = 0; i < s.size() - 1; i++){
			if(keymap[s[i] - 'a'] != keymap[s[i + 1] - 'a']) res++;
		}
		cout << res << endl;
	}
	return 0;
}