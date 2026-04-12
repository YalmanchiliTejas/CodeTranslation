#include <bits/stdc++.h>

using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	unordered_map<int,bool> row,col;
	vector<string> v;
	for(int i=0;i<h;i++) {
		string s;
		cin >> s;
		for(int j=0;j<(int)s.size();j++) {
			if(s[j]=='#') {
				col[j]=1;
				row[i]=1;
			}
		}
		v.push_back(s);
	}
	for(int i=0;i<h;i++) {
		if(row[i]) {
			for(int j=0;j<w;j++) {
				if(col[j]) {
					cout << v[i][j];
				}
			}
			cout << "\n";
		}
	}
	return 0;
}


