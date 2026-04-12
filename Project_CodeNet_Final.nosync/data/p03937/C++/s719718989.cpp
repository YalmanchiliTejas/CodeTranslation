#include <bits/stdc++.h>

using namespace std;


typedef pair<int, int> pii;

char m[10][10];
int pass[10][10];

int main() {
	int h, w;
	scanf("%d%d", &h, &w);

	for (int i = 0; i < h; i++) {
		scanf(" %s", m[i]);
	}

	queue <pii> q;
	if(m[0][0] == '#') {
		q.push(pii(0,0));
		pass[0][0] = 1;
	}
	int ok = 1;
	while(!q.empty()) {
		pii a = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (i+j != 1) continue;
				if (a.first+i >= h || a.second+j >= w) continue;
				if (m[a.first+i][a.second+j] == '#') {
					q.push(pii(a.first+i, a.second+j));
					pass[a.first+i][a.second+j] = 1;
				}
			}
		}
		if(q.size() > 1) ok = 0;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if(m[i][j] == '#') {
				if(pass[i][j] == 0) ok = 0;
			}
		}
	}
	if (ok) puts("Possible");
	else puts("Impossible");
}