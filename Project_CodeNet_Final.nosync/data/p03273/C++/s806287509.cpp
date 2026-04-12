#include <iostream>
#include <cstdio>
using namespace std;
int h, w, v[105];
char a[105][105];
int main() {
	int i, j;
	cin>>h>>w;
	for(i=0; i<h; i++) cin>>a[i];
	for(j=0; j<w; j++) {
		for(i=0; i<h && a[i][j]=='.'; i++);
		if(i==h) v[j] = 1;
	}
	for(i=0; i<h; i++) {
		for(j=0; j<w && a[i][j]=='.'; j++);
		if(j<w) {
			for(j=0; j<w; j++) {
				if(!v[j]) printf("%c", a[i][j]);
			}
			puts("");
		}
	}
	return 0;
}