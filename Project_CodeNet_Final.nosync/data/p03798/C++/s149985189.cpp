#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<functional>
#include<set>
using namespace std;
#define int long long
typedef pair<int, int>P;
int w[4][100005];
signed main() {
	int n; cin >> n;
	string s; cin >> s;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n; j++)w[i][j] --;

	w[0][0] = 0, w[0][1] = 0;
	w[1][0] = 0, w[1][1] = 1;
	w[2][0] = 1, w[2][1] = 0;
	w[3][0] = 1, w[3][1] = 1;
	int fl = 0,ans=4;
	//0=sheep,1=wolf
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= n; j++) {
			int m = j%n, l = (j + n - 1) % n, r = (j + 1) % n;
			if (w[i][m]) {//.wolf
				if (s[m] == 'o') {
					int a;
					if (w[i][l])a = 0;
					else a = 1;
					if (w[i][r] ==-1)w[i][r] = a;
					else if (w[i][r] != a)fl++;
				}
				else {
					int a;
					if (w[i][l])a = 1;
					else a = 0;
					if (w[i][r] == -1)w[i][r] = a;
					else if (w[i][r] != a)fl++;
				}
			}
			else {
				if (s[m] == 'x') {
					int a;
					if (w[i][l])a = 0;
					else a = 1;
					if (w[i][r] == -1)w[i][r] = a;
					else if (w[i][r] != a)fl++;
				}
				else {
					int a;
					if (w[i][l])a = 1;
					else a = 0;
					if (w[i][r] == -1)w[i][r] = a;
					else if (w[i][r] != a)fl++;
				}
			}
		}
		if (!fl)ans = i;
		fl = 0;
	}
	if (ans == 4)puts("-1");
	else {
		for (int i = 0; i < n; i++) {
			if (w[ans][i])cout << 'W';
			else cout << 'S';
		}
		cout << endl;
	}
}