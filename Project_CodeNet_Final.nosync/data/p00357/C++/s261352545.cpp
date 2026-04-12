
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#define px(str) cout<<(str)<<endl,exit(0);
#define pe(str) return cout<<(str)<<endl,0;
#define IF(a,b,c) ((a)?(b):(c))
#define re(i,n) for(int i=0;i<(n);i++)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define db(a) cout<<"debug:"<<(a)<<endl;
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin >> n;
	int *a=new int[n+1];
	re(i, n) {
		cin >> a[i + 1];
		a[i + 1] /= 10;
	}
	int now = 1;
	int f = 0;
	while (now) {
		int m = a[now] + now, t = 0;
		for (int i = now + 1; i <= now + a[now]; i++) {
			if (i >= n) { f = 1; break; }
			if (m<a[i] + i) {
				m = a[i] + i;
				t = i;
			}
		}
		if (f)break;
		if (t == 0)pe("no");
		now = t;
	}

	now = n;
	f = 0;
	while (now) {
		int m = -a[now] + now, t = 0;
		for (int i = now - 1; i >= now - a[now]; i--) {
			if (i <= 1) { f = 1; break; }
			if (m>-a[i] + i) {
				m = -a[i] + i;
				t = i;
			}
		}
		if (f)break;
		if (t == 0)pe("no");
		now = t;
	}
	pe("yes");
	return 0;
}

