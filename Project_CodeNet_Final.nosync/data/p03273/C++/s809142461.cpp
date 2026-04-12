#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 5;

char a[N][N]; 
int H, W, b[N][N];
bool hh[N], ww[N];

int cnt = 0;

int main(void) {
	memset(hh, true, sizeof(hh));
	memset(ww, true, sizeof(ww));
	scanf("%d%d", &H, &W);
	for (int i = 1; i <= H; ++ i) {
		scanf("%s", a[i] + 1);
		for (int j = 1; j <= W; ++ j) 
		if (a[i][j] == '.') b[i][j] = 0; else b[i][j] = 1;
		int sum = 0;
		for (int j = 1; j <= W; ++ j) sum += b[i][j];
		if (sum == 0) hh[i] = false;		
	}
	
	for (int i = 1; i <= W; ++ i) {
		int sum = 0;
		for (int j = 1; j <= H; ++ j) sum += b[j][i];
		if (sum == 0) ww[i] = false;
	}
	
	for (int i = 1; i <= H; ++ i) {
		bool ok = true;
		for (int j = 1; j <= W; ++ j) {
			if (!ww[j] || ! hh[i]) continue;
			cout << a[i][j]; ok = false;
		}
		if (! ok) cout << endl;
	}
	
	return 0;
}