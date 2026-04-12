#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(){
	int h,w;
	cin >> h >> w;
	vector<vector<char>> mp(h, vector<char>(w));
	vector<bool> skip_row(h,false), skip_col(w,false);
	rep(i,h){
		bool all_w(true);
		rep(j,w){
			cin >> mp[i][j];
			if(mp[i][j] == '#') all_w = false;
		}
		if(all_w) skip_row[i] = true;
	}
	rep(i,w){
		bool all_w(true);
		rep(j,h){
			if(mp[j][i] == '#') all_w = false;
		}
		if(all_w) skip_col[i] = true;
	}
	rep(i,h){
		if(skip_row[i] == true) continue;
		rep(j,w){
			if(skip_col[j] == true) continue;
			cout << mp[i][j];
		}
		cout << endl;
	}
	return 0;
}