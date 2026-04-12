#include<bits/stdc++.h>
using namespace std;
vector<string>grid;
bool removed[105];
int main(){
	int h,w;
	cin>>h>>w;
	for(int i=0; i<h; i++){
		string s;
		cin>>s;
		bool all_white = true;
		for(int j=0; s[j]; j++){
			if(s[j]=='#') all_white = false;
		}
		if(!all_white) grid.push_back(s);
	}
	for(int i=0; i<w; i++){
		bool all_white = true;
		for(int j=0; j<grid.size(); j++){
			if(grid[j][i]=='#') all_white = false;
		}
		if(all_white) removed[i] = true;
	}
	for(int i=0; i<grid.size(); i++){
		for(int j=0; j<w; j++){
			if(removed[j]==false) cout<<grid[i][j];
		}
		cout<<'\n';
	}
}