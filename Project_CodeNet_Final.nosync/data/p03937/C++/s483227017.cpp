#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

bool ok(pair<int,int> &p, int n, int m) {
	return (p.first<n&&p.second<m);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	vector<string> grid(n);
	for (int i=0; i<n; i++)
		cin>>grid[i];
	ii cur={0,0};
	while(1) {
		grid[cur.first][cur.second]='.';
		if(cur.first==n-1&&cur.second==m-1)
			break;
		ii right=cur, down=cur; right.second++; down.first++;
		bool update=false;
		if(ok(right,n,m)&&grid[right.first][right.second]=='#')
			cur=right, update=true;
		else if(ok(down,n,m)&&grid[down.first][down.second]=='#')
			cur=down, update=true;
		if(!update)
			break;
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if(grid[i][j]=='#') {
				cout << "Impossible" << endl;
				return 0;
			}
	cout << "Possible" << endl;
	return 0;
}
