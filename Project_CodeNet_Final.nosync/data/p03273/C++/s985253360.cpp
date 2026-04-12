#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	int H, W;
	vector<string> a;

	cin >> H >> W;
	a.resize(H);
	for(int i = 0; i < H; i++)
		cin >> a[i];

	set<int> h,w;
	for(int i = 0; i < H; i++)
		if(a[i] == string(W,'.'))
			h.insert(i);

	for(int i = 0; i < W; i++){
		bool check = true;
		for(int j = 1; j < H; j++)
			if(a[j][i] != a[j-1][i])
				check = false;
		if(check && a[0][i] == '.' && H > 1)
			w.insert(i);
	}

	for(int i = 0; i < H; i++){
		bool check = false;
		for(int j = 0; j < W; j++)
			if(h.find(i) == h.end() && w.find(j) == w.end()){
				cout << a[i][j];
				check = true;
			}
		if(check)
			cout << endl;
	}

	return 0;
}