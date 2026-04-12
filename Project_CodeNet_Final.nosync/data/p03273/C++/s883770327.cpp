#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int H,W;
	string t="";
	cin >> H >> W;
	vector<string> a(H);
	set<int> w,h;
	vector<bool> b(W,1);

	rep(i,H) {
		cin >> a.at(i);
		rep(j,W)
			if(a.at(i).at(j) == '#')
				b.at(j) = 0;
	}

	rep(i,W) {
		t += '.';
		if(b.at(i))
			w.insert(i);
	}
	rep(i,H)
		if(a.at(i) == t)
			h.insert(i);
	
	rep(i,H)
		if(!h.count(i)) {
			rep(j,W)
				if(!w.count(j))
					cout << a.at(i).at(j);
			cout << endl;
		}
}