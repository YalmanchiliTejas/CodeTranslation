#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int H,W;
	cin >> H >> W;
	string a[H];
	int cnt=0;
	for(int i=0; i<H; i++) {
		cin >> a[i];
		for(int j=0; j<W; j++) {
			if(a[i].at(j)=='#') cnt++;
		}
	}
	if(cnt==H+W-1) cout << "Possible" << endl;
	else           cout << "Impossible" << endl;
}