#include <bits/stdc++.h>
using namespace std;
char ch[150][150];
bool vis[150][150];	
int n,m;
bool flag = true;
void y() {
	flag = true;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(ch[j][i] != '.') {
				flag = false;
				break;
			}
		}
		if(flag) {
			for(int k = 1; k <= n; k++) {
				vis[k][i] = false;
			}
		}
		flag = true;
	}
	return;
}
void x() {
	flag = true;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(ch[i][j] != '.') {
				flag = false;
				break;
			}
		}
		if(flag) {
			for(int k = 1; k <= m; k++) {
				vis[i][k] = false;
			}
		}
		flag = true;
	}
	return;
}
void print() {
	flag = false;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(vis[i][j]) {
				cout<<ch[i][j];
				flag = true;
			}
		}
		if(flag)cout<<endl;
		flag = false;
	}
	return;
}
void init() {
	memset(vis,true,sizeof(vis));
}
void read() {
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin>>ch[i][j];
		}
	}
	return;
}
int main() {
	init();
	read();
	x();
	y();
	print();
	return 0;
}