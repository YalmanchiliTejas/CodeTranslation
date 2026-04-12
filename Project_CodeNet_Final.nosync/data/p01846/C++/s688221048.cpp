#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
int main() {
	string s;
	while (cin >> s) {
		if (s == "#")break;
		char board[10][10];
		int cnth = 0; int cntw = 0;
		int len = s.length();
		rep(i, len) {
			if (s[i] == '/') {
				cnth++; cntw = 0;
			}
			else if (s[i] == 'b') {
				board[cnth][cntw] = 'b'; cntw++;
			}
			else {
				rep(j, (s[i] - '0')) {
					board[cnth][cntw] = '.';
					cntw++;
				}
			}
		}
		cnth++;
		int a, b, c, d;
		cin >> a >> b >> c >> d; a--; b--; c--; d--;
		swap(board[a][b], board[c][d]);
		rep(i, cnth) {
			int cnt = 0;
			rep(j, cntw) {
				if (board[i][j] == '.') {
					cnt++;
				}
				else {
					if (cnt > 0) {
						cout << cnt;
					}
					cout << 'b';
					cnt = 0;
				}
			}
			if (cnt > 0)cout << cnt;
			if (i < cnth - 1) {
				cout << '/';
			}
		}
		cout << endl;
	}
	return 0;
}
