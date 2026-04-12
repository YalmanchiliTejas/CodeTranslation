#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {

	int h, w;
	cin >> h >> w;

	int p = 0;
	rep(i, 0, h) {
		rep(j, 0, w) {
			char a;
			cin >> a;
			if (a == '#') {
				if (p < j) p = j;
				if (p > j) {
					cout << "Impossible" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Possible" << endl;

	return 0;
}