#include <iostream>
#include <string>
#define llint long long
#define inf 1e18

using namespace std;

string s;
llint sx, sy, tx, ty;
bool b[15][15];

int main(void)
{
	while(1){
		cin >> s;
		if(s == "#") break;
		cin >> sy >> sx >> ty >> tx;
		
		for(int y = 1; y < 15; y++){
			for(int x = 1; x < 15; x++){
				b[x][y] = false;
			}
		}
		
		llint x = 1, y = 1;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'b'){
				b[x][y] = true;
				x++;
			}
			else if(s[i] == '/'){
				y++;
				x = 1;
			}
			else{
				x += s[i] - '0';
			}
		}
		llint w = x-1, h = y;
		
		b[sx][sy] = false, b[tx][ty] = true;
		
		string ans;
		for(int y = 1; y <= h; y++){
			llint cnt = 0;
			for(int x = 1; x <= w; x++){
				if(b[x][y]){
					if(cnt > 0) ans += cnt+'0';
					cnt = 0;
					ans += 'b';
				}
				else cnt++;
			}
			if(cnt > 0) ans += cnt+'0';
			if(y < h) ans += "/";
		}
		cout << ans << endl;
	}
	
	return 0;
}
