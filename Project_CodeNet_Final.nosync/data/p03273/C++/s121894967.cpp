#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<iterator>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector <string> a(h);
	rep(i, h) {
		cin >> a[i];
	}
	vector <bool>r(h, 0);
	vector <bool>c(w, 0);
	rep(i, h) {
		rep(j, w) {
			if (a[i][j]=='#') {
				r[i] = 1;
				c[j] = 1;
			}
		}
	}

	rep(i, h) {
		if (r[i]) {
			rep(j, w) {
				if (c[j])cout << a[i][j];
			}
			cout << endl;
		}
		
	}
}