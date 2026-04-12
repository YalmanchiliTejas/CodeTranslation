#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)

int d[6];
void init() {
	rep(i,6) {
		d[i] = i + 1;
	}
}
void north() {
	int buf = d[0];
	d[0] = d[1];
	d[1] = d[5];
	d[5] = d[4];
	d[4] = buf;
}
void south() {
	rep(i,3) {
		north();
	}
}
void east() {
	int buf = d[0];
	d[0] = d[3];
	d[3] = d[5];
	d[5] = d[2];
	d[2] = buf;
}
void west() {
	rep(i,3) {
		east();
	}
}
void right() {
	int buf = d[1];
	d[1] = d[2];
	d[2] = d[4];
	d[4] = d[3];
	d[3] = buf;
}
void left() {
	rep(i,3) {
		right();
	}
}
int main() {
	int n;
	while(1) {
		cin >> n;
		if(n == 0) break;
		init();
		string s;
		int ret = 1;
		rep(i,n){ 
			cin >> s;
			if(s[0] == 'N') north();
			else if(s[0] == 'W') west();
			else if(s[0] == 'E') east();
			else if(s[0] == 'S') south();
			else if(s[0] == 'R') right();
			else left();
			ret += d[0];
		}
		cout << ret << endl;
	}
	return 0;
}