#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> v;
bool a[101], b[101];

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> h >> w;
	for(int i=0; i<h; ++i){
		string s;
		cin >> s;
		v.push_back(s);
	}
	for(int i=0; i<h; ++i){
		bool f = true;
		for(int j=0; j<w; ++j)
			if(v[i][j] == '#'){
				f = false;
				break;
			}
		if(f) a[i] = true;
	}
//	for(int i=0; i<h; ++i)
//		if(a[i]) cout << i << "\n";
	for(int i=0; i<w; ++i){
		bool f = true;
		for(int j=0; j<h; ++j)
			if(v[j][i] == '#'){
				f = false;
				break;
			}
		if(f) b[i] = true;
	}
//	for(int i=0; i<w; ++i)
//		if(b[i]) cout << i << "\n";
	for(int i=0; i<h; ++i){
		if(a[i]) continue;
		for(int j=0; j<w; ++j){
			if(b[j]) continue;
			cout << v[i][j];
		}
		cout << "\n";
	}
}