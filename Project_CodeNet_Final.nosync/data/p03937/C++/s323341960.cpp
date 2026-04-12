#include<bits/stdc++.h>

using namespace std;

const int maxn = 10;
int h, w, a[maxn][maxn], cunt;
int f(int i, int j);

bool ok(int i, int j) {
	if(a[i][j] == 1) {
		if(i == 0 and j == 0 ) {
			return false;
		}
		if(a[i - 1][j] == 1 xor a[i][j - 1] == 1) {
			if(a[i - 1][j] == 1){
				return ok(i - 1, j);
			}
			else{
				return ok(i, j - 1);
			}
		}
		else{
		    return true;
		}
	}
	else{
		return true;
	}
}

int main()
{
	string s[maxn];
	cin >> h >> w;
	for(int i = 0; i < h; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(s[i][j] == '#') {
				a[i][j] = 1;
				cunt++;
			}
		}
	}
	if(cunt != h + w - 1) {
		cout << "Impossible";
		return 0;
	}
	if(ok(h - 1, w - 1)) {
		cout << "Impossible";
		return 0;
	}
	else{
		cout << "Possible";
	}
}
