#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

const int INF = 10000000;
using namespace std;
typedef long long  ll;
/** Problem0131 : Coctor's Strange Particles **/
// true : 点灯  false : 消灯
bool board[10][10];
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void flip(int x, int y)
{
	int nx, ny;
	board[x][y] = !board[x][y];
	rep(i, 4) {
		nx = x+dx[i]; ny = y+dy[i];
		if (0 <= nx && nx < 10 && 0 <= ny && ny < 10)
			board[nx][ny] = !board[nx][ny];
	}
}

int main()
{
	int n;
	bool stamp[10][10];
	bool copy[10][10];
	cin >> n;
	while (n-- > 0) {
		rep(j,10) rep(k,10) {
			int c;
			cin >> c;
			board[k][j] = c==1;
			copy[k][j] = board[k][j];
		}
		
		/** Lights-Out Game Mode
		while (1) {
			int x, y;
			cin >> x >> y;
			flip(x, y);
			
			rep(y, 10) {
				if (board[0][y])
					cout << '1';
				else
					cout  << '0';
				REP(x, 1, 10) {
					if (board[x][y])
						cout << ' ' << '1';
					else
						cout << ' ' << '0';
				}
				cout << endl;
			}
		} **/
		
		
		for (int i=0; i<1024; i++) {
			rep(y, 10) rep(x, 10) board[x][y] = copy[x][y];
		
			rep(j, 10) {
				stamp[j][0] = (i>>j&1);
			}
			rep(j, 10) {
				if (stamp[j][0])
					flip(j, 0);
			}
			
			for (int y=1; y<10; y++) {
				for (int x=0; x<10; x++) {
					if (board[x][y-1]) {
						stamp[x][y] = true;
						flip(x, y);
					} else {
						stamp[x][y] = false;
					}
				}
			}
			
			bool flag=true;
			rep(j, 10) {
				if (board[j][9]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				rep(y, 10) {
					if (stamp[0][y])
						cout << '1';
					else
						cout << '0';
					
					REP(x, 1, 10) {
						if (stamp[x][y])
							cout << ' ' << '1';
						else
							cout << ' ' << '0';
					}
					cout << endl;
				}
				break;
			}
		}
	}
	return 0;
}