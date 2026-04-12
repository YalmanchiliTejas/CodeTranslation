#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
char s[107][107];
bool vis[107];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%s", s[i]);
	for(int i = 1; i <= n; i++) {
		bool flag = 1;
		for(int j = 0; j < m; j++) {
			if(s[i][j] != '.') {
				flag = 0;
				break;
			}
		}
		if(flag) vis[i] = 1;
	}
	for(int j = 0; j < m; j++) {
		bool flag = 1;
		for(int i = 1; i <= n; i++) {
			if(s[i][j] != '.') {
				flag = 0;
				break;
			}
		}
		if(flag) {
			for(int i = 1; i <= n; i++) s[i][j] = '!';
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			for(int j = 0; j < m; j++) {
				if(s[i][j] != '!') printf("%c", s[i][j]);
				if(j == m - 1) printf("\n");
			}
		}
	}
}