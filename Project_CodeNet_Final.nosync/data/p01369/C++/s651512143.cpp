#include <iostream> 
#include <string>

using namespace std;
bool qwerty(char);

bool qwerty(char s){
	if(s == 'y'||s == 'u'||s == 'i'||s == 'o' || s == 'p' || s == 'h'||
		s == 'j'||s == 'k'||s == 'l'||s == 'n' || s == 'm'){
		return true;
	}else if(s == 'q'||s == 'w'||s == 'e'||s == 'r' || s == 't' || s == 'a'||
		s == 's'||s == 'd'||s == 'f'||s == 'g' || s == 'z'||
		s == 'x'||s == 'c'||s == 'v' || s == 'b'){
		return false;
	}
	return true;
}

int main(void){
	string s;
	bool fg,pre;
	int change = 0;

	getline(cin,s);
	
	while(s != "#")
	{
		pre = qwerty(s[0]);
		for(int i = 1;i < s.length();i++)
		{
			fg = qwerty(s[i]);
			if(pre != fg){
				change++;
			}
			pre = fg;
		}
		cout << change << endl;
		change = 0;
		getline(cin,s);
	}

	return 0;
}