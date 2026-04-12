#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	int h,w;
	vector<string> a;

	cin >> h >> w;
	a.resize(h+1);
	for(int i = 0; i < h; i++)
		cin >> a[i];

	bool check = true;
	for(int i = 0; i < h; i++){
		bool go = false;
		for(int j = 0; j < w; j++){
			if(!go && a[i][j] == '.' && a[i+1][j] == '#')
				check = false;
			if(go && a[i][j] == '#' && a[i+1][j] == '.')
				check = false;
			if(a[i][j] == '#' && a[i+1][j] == '#')
				if(go)
					check = false;
				else
					go = true;
		}
	}

	if(check)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;

	return 0;
}