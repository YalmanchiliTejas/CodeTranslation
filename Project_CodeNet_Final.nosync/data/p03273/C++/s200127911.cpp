#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1

int main()
{	
	ios_base::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m){
		vector<string> grid;
		string str;
		for(int i=0; i<n; i++){
			cin>>str;
			int dot=0;
			for(int j=0; j<m; j++) dot+=(str[j]=='.');
			if(dot!=m) grid.push_back(str);
		}
		vector<int> skip(m,0);
		for(int i=0; i<m; i++){
			int dot = 0;
			for(int j=0; j<grid.size(); j++){
				dot+=(grid[j][i]=='.');
			}
			if(dot==grid.size()) skip[i] = 1;
		}
		for(int i=0; i<grid.size(); i++){
			str = "";
			for(int j=0; j<m; j++){
				if(skip[j]==0) str+=grid[i][j];
			}
			if(!str.empty()) cout<<str<<endl;
		}
	}
}