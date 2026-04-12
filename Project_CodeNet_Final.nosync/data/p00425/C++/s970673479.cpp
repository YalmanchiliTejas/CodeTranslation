#include <bits/stdc++.h>
using namespace std;
int Q; string s;
int main() {
	while(cin >> Q, Q) {
		int a[3] = { 1, 2, 3 };
		int ret = 1;
		while(Q--) {
			cin >> s;
			if(s[0] == 'N') swap(a[0], a[1]), a[1] = 7 - a[1];
			if(s[0] == 'E') swap(a[0], a[2]), a[0] = 7 - a[0];
			if(s[0] == 'W') swap(a[0], a[2]), a[2] = 7 - a[2];
			if(s[0] == 'S') swap(a[0], a[1]), a[0] = 7 - a[0];
			if(s[0] == 'R') swap(a[1], a[2]), a[2] = 7 - a[2];
			if(s[0] == 'L') swap(a[1], a[2]), a[1] = 7 - a[1];
			ret += a[0];
		}
		cout << ret << endl;
	}
}