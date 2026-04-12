#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

#define MOD 1000000007;

int main(){
	int h, w;
	cin >> h >> w;
	string judge;
	for(int i=0; i<w; i++)
		judge.push_back('.');
	vector<string> grid;
	for(int i=0; i<h; i++){
		string s;
		cin >> s;
		if(s!=judge)
			grid.emplace_back(s);
	}
	for(int i=0; i<grid[0].size(); i++){
		bool flag=true;
		for(int j=0; j<grid.size(); j++){
			if(grid[j][i]=='#')
				flag=false;
		}
		if(flag){
			for(int j=0; j<grid.size(); j++)
				grid[j].erase(grid[j].begin()+i);
			i--;
		}
	}
	for(auto e: grid)
		cout << e << endl;
	return 0;
}
