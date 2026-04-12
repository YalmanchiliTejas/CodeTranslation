#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edge(n,vector<int>(n,0));
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		edge[a][b]=1;
		edge[b][a]=1;
	}
	vector<int> v(n-1);
	iota(v.begin(),v.end(),1);
	int res=0;
	do{
		
		bool isok=true;
		for(int i=0;i<n-1;i++){
			if(i==0){
				if(!edge[0][v[0]]) isok=false;
			}
			else if(!edge[v[i-1]][v[i]]) isok=false;
		}
		if(isok) res++;
	}while(next_permutation(v.begin(),v.end()));
	cout<<res<<endl;
	return 0;
}
