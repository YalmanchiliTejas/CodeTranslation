#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	vector<string> grid;
	string row;
	for (int i=0; i<n; i++) {
		cin>>row;
		int cur=0;
		for (int j=0; j<m; j++)
			if(row[j]=='.')
				cur++;
		if(cur!=m)
			grid.push_back(row);
	}
	n=grid.size();
	for (int j=0; j<m; j++) {
		int cur=0;
		for (int i=0; i<n; i++)
			if(grid[i][j]=='.')
				cur++;
		if(cur==n) {
			for (int i=0; i<n; i++)
				grid[i][j]='@';
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			if(grid[i][j]!='@')
				cout << grid[i][j];
		cout << endl;
	}
	return 0;
}
