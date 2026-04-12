#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,m,res = 0;
	cin >> n >> m;
	vector<vector <bool>> g;
	vector<int> k;
	g.resize(n);
	k.resize(n);
	for(int i=0;i<n;++i){
		g[i].resize(n);
		k[i] = i;
		for(int j=0;j<n;++j){
			g[i][j] = false;
		}
	}
	for(int i=0;i<m;++i){
		int from,to;
		cin >> from >> to;
		g[from-1][to-1] = 1;
		g[to-1][from-1] = 1;
	}
	do{
		bool flag = true;
		if(k[0]!=0)break;
		for(int i=1;i<n;++i){
			int from = k[i-1],to = k[i];
			if(!g[from][to]){
				flag = false;
				break;
			}
		}
		if(flag)res++;
	}while(next_permutation(k.begin(),k.end()));
	cout << res << endl;
}
