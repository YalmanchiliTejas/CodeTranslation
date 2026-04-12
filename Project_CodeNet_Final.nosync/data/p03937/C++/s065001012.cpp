//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,w,i,j,k,l,m,n,x,y;
	string	ans = "Possible";
	string	s;
	cin >> h >> w;
	vector<string>	bd(h);
	for(i=0;i<h;i++) cin >> bd[i];
	x = y = 0;
	if (bd[0][0]!='#') {
		ans = "Impossible";
	}
	bd[0][0] = 'o';
	while(x!=(w-1) || y!=(h-1)) {
		if (x!=(w-1)) {
			if (bd[y][x+1] == '#') {
				bd[y][x+1] = 'o';
				x++;
				continue;
			}
		}
		if (y!=(h-1)) {
			if (bd[y+1][x] == '#') {
				bd[y+1][x] = 'o';
				y++;
				continue;
			}
		}
		ans = "Impossible";
		break;
	}
	for(i=0;i<h;i++) for(j=0;j<w;j++) {
		if (bd[i][j]=='#') {
			ans = "Impossible";
			break;
		}
	}
	//for(i=0;i<h;i++) cout << bd[i] << endl;
	cout << ans << endl;
	return 0;
}
