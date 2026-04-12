#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, w, a=0;
	cin >> h >> w;
	for(int i=0; i<h; ++i) {
		string s;
		cin >> s;
		for(char c : s)
			a+=c=='#';
	}
	cout << (a==h+w-1?"Possible":"Impossible");
}