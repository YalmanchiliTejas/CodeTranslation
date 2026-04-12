#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	char c[11][11];
	string s;
	int w,h,x,a,b,e,d;
	while(1){
		cin >> s;
		if(s[0] == '#')break;
		for(int i = 0;i <= 10;i++){
			for(int j = 0;j <= 10;j++){
				c[i][j] = 'o';
			}
		}

		w = h = 1;
		for(int i = 0;i < s.size();i++){
			if(s[i] == '/'){
				w = 1;
				h++;
				continue;
			}
			else if(s[i] == 'b'){
				c[h][w] = 'b';
				w++;
			}
			else{
				stringstream ss;
				ss << s[i];
				ss >> x;
				for(int j = 0;j < x;j++){
					c[h][w] = '.';
					w++;
				}
			}
		}

		cin >> a >> b >> e >> d;
		c[a][b] = '.';
		c[e][d] = 'b';

		for(int i = 1;i <= 10;i++){
			a = 0;
			if(c[i][1] == 'o')break;
			for(int j = 1;j <= 10;j++){
				if(c[i][j] == '.'){
					a++;
				}
				else if(c[i][j] == 'b'){
					if(a != 0){
						cout << a;
						a = 0;
					}
					cout << 'b';
				}		
				else{
					if(a != 0)cout << a;
					if(c[i+1][1] != 'o')cout << '/';
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}