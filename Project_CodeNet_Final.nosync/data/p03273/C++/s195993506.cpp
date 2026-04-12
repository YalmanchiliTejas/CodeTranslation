#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	vector<int> g(h);
	vector<int> r(w);
	rep(i, h) cin >> s.at(i);
	rep(i, h){
		int f = 0;
		rep(j, w) if(s.at(i).at(j) == '#') f = 1;
		if(f == 0) g.at(i) = 1;
	}
	rep(i, w){
		int f = 0;
		rep(j, h) if(s.at(j).at(i) == '#') f = 1;
		if(f == 0) r.at(i) = 1;
	}
	rep(i, h){
		if(g.at(i) == 0){
			rep(j, w) if(r.at(j) == 0) cout << s.at(i).at(j);
			cout << endl;
		}
	}
	return 0;
}