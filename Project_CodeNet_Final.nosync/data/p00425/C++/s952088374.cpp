#include <iostream>
#include <string>

using namespace std;

int main()
{
	int top, bot, r, l, f, b, n, s, t;
	string str;
	
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		top = 1;
		bot = 6;
		r = 3;
		b = 2;
		f = 5;
		l = 4;
		s = 1;
		while(n--){
			cin >> str;
			
			if(str == "North"){
				t = top;
				top = b;
				b = bot;
				bot = f;
				f = t;
			} else if(str == "East"){
				t = top;
				top = l;
				l = bot;
				bot = r;
				r = t;
			} else if(str == "South"){
				t = top;
				top = f;
				f = bot;
				bot = b;
				b = t;
			} else if(str == "West"){
				t = top;
				top = r;
				r = bot;
				bot = l;
				l = t;
			} else if(str == "Right"){
				t = b;
				b = r;
				r = f;
				f = l;
				l = t;
			} else if(str == "Left"){
				t = b;
				b = l;
				l = f;
				f = r;
				r = t;
			}
			s += top;
		}
		
		cout << s << endl;
	}
	
	return 0;
}