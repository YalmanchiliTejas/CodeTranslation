#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=15;
bool conn[mx][mx];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	for (int i=0; i<m; i++) {
		int x,y; cin>>x>>y;
		conn[x][y]=conn[y][x]=true;
	}
	vector<int> p(n);
	for (int i=1; i<=n; i++)
		p[i-1]=i;
	int ret=0;
	do {
		bool ok=p[0]==1;
		for (int i=1; i<n; i++)
			if(!conn[p[i-1]][p[i]])
				ok=false;
		if(ok) ret++;
	} while(next_permutation(p.begin(),p.end()));
	cout<<ret<<"\n";
	return 0;
}