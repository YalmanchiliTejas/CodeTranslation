#include <bits/stdc++.h>
using namespace std;


bool is[102][102];
int main(){
	int h,w; cin>>h>>w;
	char grid[102][102];
	for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin>>grid[i][j];
	for(int i=0;i<h;i++){
		bool z=true;
		for(int j=0;j<w;j++){
			if(grid[i][j]=='#') z=false;
		}
		if(z) for(int j=0;j<w;j++) is[i][j]=true;
	}	
	for(int j=0;j<w;j++){
		bool zz=true;
		for(int i=0;i<h;i++) if(grid[i][j]=='#') zz=false;
		if(zz) for(int i=0;i<h;i++) is[i][j]=true;
	}
		
	vector<string> v;
	for(int i=0;i<h;i++){
		string s;
		for(int j=0;j<w;j++) if(!is[i][j]){
			s.push_back(grid[i][j]);
		}
		if(!s.empty()) v.push_back(s);
	}
	for(string i:v) cout<<i<<endl;
}
