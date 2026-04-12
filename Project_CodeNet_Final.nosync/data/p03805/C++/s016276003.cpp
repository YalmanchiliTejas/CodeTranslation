#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,m;
	cin>>n>>m;

	vector<vector<int>> g(n,vector<int>(n));
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x-1][y-1] = g[y-1][x-1] = 1;
	}

	vector<int> p(n);
	for(int i=0;i<n;i++) p[i] = i;

		int res = 0;
	do {
		bool ok = 1;
		for(int i=0;i<(int)p.size()-1;i++){
			ok&=g[p[i]][p[i+1]];
		}
		if(ok) res++;
	} while(next_permutation(p.begin()+1,p.end()));

	cout<<res;
}